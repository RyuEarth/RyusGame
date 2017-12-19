#include "Enemy.h"
#include "Zako.h"
#include "Player.h"
#include "DxLib.h"
#include "Boss.h"
#include "Define.h"
#include "GameMgr.h"
#include <vector>
using namespace std;

Enemy::Enemy(Player* player,GameMgr* gamemgr) {
	pPlayer = player;
	mGameMgr = gamemgr;
	int tmp = LoadDivGraph("Image/put_enemy.png", 9, 3, 3, 32, 32, Image_zako);
	if (tmp == -1) {
		printfDx("enemy load error");
		DxLib_End();
	}
	mZakoState = 0;
	mvZako = new vector<Zako>;
	mvBoss = new vector<Boss>;
	Load_story();//Load_story()の中にIniialize()が存在
}
Enemy::~Enemy() {
}

void Enemy::Initialize() {
	for (int i = 0; i < (*mvZako).size(); i++) {
		(*mvZako)[i].Initialize();
	}
	
}

void Enemy::Load_story() {
		int n, num, i, fp;
		char fname[32] = { "csv/storyH0.csv" };
		int input[64];
		char inputc[64];

		fp = FileRead_open(fname);//ファイル読み込み
		if (fp == NULL) {
			printfDx("read error");
			DxLib_End();
			return;
		}
		for (i = 0; i<2; i++)//最初の2行読み飛ばす
			while (FileRead_getc(fp) != '\n');

		n = 0, num = 0;
		while (1) {
			for (i = 0; i<64; i++) {
				inputc[i] = input[i] = FileRead_getc(fp);//1文字取得する
				if (inputc[i] == '/') {//スラッシュがあれば
					while (FileRead_getc(fp) != '\n');//改行までループ
					i = -1;//カウンタを最初に戻して
					continue;
				}
				if (input[i] == ',' || input[i] == '\n') {//カンマか改行なら
					inputc[i] = '\0';//そこまでを文字列とし
					break;
				}
				if (input[i] == EOF) {//ファイルの終わりなら
					goto EXFILE;//終了
				}
			}
			switch (num) {
			case 0: enemy_order[n].cnt = atoi(inputc); break;
			case 1: enemy_order[n].pattern = atoi(inputc); break;
			case 2: enemy_order[n].knd = atoi(inputc); break;
			case 3: enemy_order[n].x = atof(inputc); break;
			case 4: enemy_order[n].y = atof(inputc); break;
			case 5: enemy_order[n].sp = atof(inputc); break;
			case 6: enemy_order[n].bltime = atoi(inputc); break;
			case 7: enemy_order[n].blknd = atoi(inputc); break;
			case 8: enemy_order[n].col = atoi(inputc); break;
			case 9: enemy_order[n].hp = atoi(inputc); break;
			case 10:enemy_order[n].blknd2 = atoi(inputc); break;
			case 11:enemy_order[n].wait = atoi(inputc); break;
			case 12:enemy_order[n].item_n[0] = atoi(inputc); break;
			case 13:enemy_order[n].item_n[1] = atoi(inputc); break;
			case 14:enemy_order[n].item_n[2] = atoi(inputc); break;
			case 15:enemy_order[n].item_n[3] = atoi(inputc); break;
			case 16:enemy_order[n].item_n[4] = atoi(inputc); break;
			case 17:enemy_order[n].item_n[5] = atoi(inputc); break;
			}
			num++;
			if (num == 18) {
				num = 0;
				n++;
			}
		}

	EXFILE:
		enemy_num = n;
		

		
		

		FileRead_close(fp);
	

}


void Enemy::bossMgr(int boss_knd) {
		//ボスを登録
	if (boss_knd != -1) {
		mGameMgr->mStageCountGoFlag = 0;//ステージカウントをストップ
		(*mvBoss).push_back(Boss(pPlayer->mVec, mvZako, boss_knd));
		mGameMgr->mStageCount++;//多重動的確保防止のためフレームを1ずらす
	}

	if ((*mvBoss).size() > 0 && mGameMgr->mStageCountGoFlag == 0) {
		(*mvBoss).back().Process();//現在存在しているボスを計算
		if ((*mvBoss).back().mFlag == 0) {
			mGameMgr->mStageCountGoFlag = 1;//ステージカウントを進行
		}
	}
}
void Enemy::Process() {
	//enter
	for (int i = 0; i < enemy_num; i++) {
		if (enemy_order[i].cnt == mGameMgr->mStageCount) {

				(*mvZako).push_back(Zako(enemy_order[i], Image_zako, pPlayer->mVec));

		}
	}
	
	//calc
	int i;
	for (i = 0; i <(*mvZako).size() ; i++) {
		(*mvZako)[i].Process();

	}

	/*
	===注意！ここで雑魚を削除すると弾幕も削除される====
	vector<Zako>::iterator pZako = (*mvZako).begin();
	for (i = 0; i < (*mvZako).size(); i++) {
	if ((*mvZako)[i].mFlag == 0) {
	pZako = (*mvZako).begin();
	pZako += i;
	(*mvZako).erase(pZako);
	}
	}
	*/

	//以下ボス登録・計算
	int boss_knd=0;
	switch (mGameMgr->mStageCount) {
	case BossEnterCnt::BOSS_CNT_00:
		boss_knd = BossKnd::BOSS_KND_00;
		break;
	default:
		boss_knd = -1;
		break;
	}
	bossMgr(boss_knd);

}

void Enemy::Draw() {
	//雑魚描画
	for (int i = 0; i <(*mvZako).size(); i++) {
		(*mvZako)[i].Draw();
	}
	//ボス描画
	if ((*mvBoss).size() > 0) {
		(*mvBoss).back().Draw();
	}
}

void Enemy::Finalize() {
	int i;
	for (i = 0; i < (*mvZako).size(); i++) {
		(*mvZako)[i].Finalize();
	}

}



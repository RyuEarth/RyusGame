#include "OutMgr.h"
#include "Enemy.h"
#include "Boss.h"
#include "Zako.h"
#include "Player.h"
#include "Vector2.h"
#include "math.h"
#include "Define.h"
#include "PlayerShot.h"
#include "PlayerBullet.h"
#include "EffectMgr.h"
#include "Music.h"
#include "Zako.h"
#include "ZakoShot.h"
#include "BossShot.h"
#include "Bullet.h"
#include "Key.h"
#include "DxLib.h"


//誰と誰が衝突するかのパターン
enum outpattern {
	PLAYER_ZAKO,
	PLAYERSHOT_ZAKO,
	ZAKOSHOT_PLAYER,
	PLAYERSHOT_BOSS,
	BOSSSHOT_PLAYER,
	PLAYER_BOSS
};
//衝突する敵の種類（使うかどうかは保留）
enum outzako {
	KND1,
	KND2,
	KND3,
	KND4,
	KND5,

};

//あたり判定のパターン

OutMgr::OutMgr() {
	mEffect_flag = false;
	mEffect_flag_teki = false;
	mBombCount = -1;
	mBombFlag = false;
	mEnemyHit = 0;
	mBossHitFlag = 0;
	mBombNum = 5;
}

OutMgr::~OutMgr() {
	
}

void OutMgr::Initialize() {
	mEnemy_num = mEnemy_data->Get_enemy_num();
	tmp_zako = &mEnemy_data->Get_zako();
	tmp_boss = &mEnemy_data->Get_boss();

}

void OutMgr::outCalcPlayerAndZako() {
	int i;
	int tmp_out = static_cast<int>(outpattern::PLAYER_ZAKO);
	for (i = 0; i < (*tmp_zako).size(); i++) {

		if ((*tmp_zako)[i].mFlag) {
			if (mPlayer_data->mMuteki_flag == false) {

				if (Collision((*tmp_zako)[i].Get_vector(), mPlayer_data->Get_vector(), tmp_out)) {

					mPlayer_data->mMuteki_flag = true;
					mPlayer_data->mCount = 0;
					mPlayer_data->mDeleteFlag = true;
					mPlayer_data->mFlag = false;
					mPlayer_data->mDeathFlag = true;
					if (!(mPlayer_data->mLife < 0)) {
						EffectMgr::Instance()->effEnter2(mPlayer_data->Get_vector(), EffectKnd::HADOU_EFF, 0, 10, 3);
						Music::Instance()->enterSe(2);
					}
					


					
				}
			}
		}
	}
}

void OutMgr::outCalcBomb() {
	int i;
	int tmp_out = static_cast<int>(outpattern::PLAYER_ZAKO);
	if (mBombNum > 0) {
		if (!(mPlayer_data->mLife < 0)) {
			if (Key_get(KEY_INPUT_X) == 1) {
				mPlayer_data->mMuteki_flag = true;
				mPlayer_data->mCount = 0;
				mPlayer_data->mDeleteFlag = true;
				mPlayer_data->mMuteki_count = 0;
				mBombFlag = true;//ボムフラグあげ
				mBombCount = 0;
				mBombNum--;
				EffectMgr::Instance()->effEnter2(mPlayer_data->Get_vector(), EffectKnd::HADOU_EFF, 0, 10, 3);
				EffectMgr::Instance()->effEnter2(mPlayer_data->Get_vector(), EffectKnd::DELETE_EFF01, 0, 2, 3);
				Vector2 *vec = new Vector2(250, 300);
				EffectMgr::Instance()->effEnter2(vec, EffectKnd::CHARA_EFF00, 30, 1, 1);
				Music::Instance()->enterSe(1);


			}
		}
	}


	if (mBombFlag) {
		if (0<=mBombCount&&mBombCount < 200) {
			//雑魚
			for (int i = 0; i < (*tmp_zako).size(); i++) {
				if ((*tmp_zako)[i].mFlag == true || !(*tmp_zako)[i].mvZakoShot->empty()) {
					if (SCREEN_X_MIN+50 < (*tmp_zako)[i].Get_vector()->x && (*tmp_zako)[i].Get_vector()->x < SCREEN_X_MAX-50&&
						SCREEN_Y_MIN+50 < (*tmp_zako)[i].Get_vector()->y&&(*tmp_zako)[i].Get_vector()->y<SCREEN_Y_MAX-50) {
						vector<ZakoShot> *tmp_zakoshot = (*tmp_zako)[i].mvZakoShot;
						for (int j = 0; j < (*tmp_zakoshot).size();j++) {
							vector<Bullet> *tmp_zakobullet = (*tmp_zakoshot)[j].mvBullet;
							for (int k = 0; k < (*tmp_zakobullet).size(); k++) {
								EffectMgr::Instance()->effEnter((*tmp_zakobullet)[k].mVec, EffectKnd::DELETE_EFF00);
								(*tmp_zakobullet)[k].mFlag = 0;
							}
							
						}
						if ((*tmp_zako)[i].mFlag) {
							EffectMgr::Instance()->effEnter((*tmp_zako)[i].Get_vector(), EffectKnd::DELETE_EFF00);
							EffectMgr::Instance()->effEnter2((*tmp_zako)[i].Get_vector(), EffectKnd::DELETE_EFF00, 0, 4, 4);
							(*tmp_zako)[i].mFlag = false;//出現中の敵はすべて殺す
						}
			
						mEnemyHit++;
					}
				}

			}
			//ボス
			for (int i = 0; i < (*tmp_boss).size(); i++) {
				if ((*tmp_boss)[i].mFlag == 1) {
					if (SCREEN_X_MIN + 50 < (*tmp_boss)[i].Get_vector()->x && (*tmp_boss)[i].Get_vector()->x < SCREEN_X_MAX - 50 &&
						SCREEN_Y_MIN + 50 < (*tmp_boss)[i].Get_vector()->y && (*tmp_boss)[i].Get_vector()->y<SCREEN_Y_MAX - 50) {
						if (mBombCount == 0) {
							(*tmp_boss)[i].mHp -= 5;//ボスのhpを5減らす
							vector<BossShot> *tmp_bossshot = (*tmp_boss)[i].mvBossShot;
							for (int j = 0; j < (*tmp_bossshot).size(); j++) {
								vector<Bullet> *tmp_bossbullet = (*tmp_bossshot)[j].mvBullet;
								for (int k = 0; k < (*tmp_bossbullet).size(); k++) {
									EffectMgr::Instance()->effEnter((*tmp_bossbullet)[k].mVec, EffectKnd::DELETE_EFF00);
									(*tmp_bossbullet)[k].mFlag = 0;
								}
							}
						}
						

						mEnemyHit++;
					}


				}
			}
			mBombCount++;
		}
		else {
			mBombFlag = false;
			mBombCount = -1;

		}

	}
	
}
void OutMgr::outCalcPlayerShotAndZako() {
	//zakoの種類を解析
	int i;
	for (i = 0; i < (*tmp_zako).size(); i++) {

		if ((*tmp_zako)[i].mFlag) {
			
				//ここにショットと敵のコリジョンをいれる
			for (int k = 0; k < C_BULLET_NUM; k++) {
				if (mPlayer_data->pPlayerShot->get_Bullet(k)->flag) {
					if (Collision((*tmp_zako)[i].Get_vector(),
						mPlayer_data->pPlayerShot->get_Bullet(k)->Get_vec(),
						outpattern::PLAYERSHOT_ZAKO)) {
						Music::Instance()->enterSe(3);
						(*tmp_zako)[i].mDeleteFlag = true;
						(*tmp_zako)[i].mFlag = false;
						EffectMgr::Instance()->effEnter((*tmp_zako)[i].Get_vector(),EffectKnd::DELETE_EFF00);
						EffectMgr::Instance()->effEnter2((*tmp_zako)[i].Get_vector(), EffectKnd::DELETE_EFF00,0, 4, 4);
						
						mPlayer_data->pPlayerShot->get_Bullet(k)->flag = false;
						mEnemyHit++;
					}

				}
			}


			
		}
	}
}
void OutMgr::outCalcZakoShotAndPlayer() {
	int i,j,k;
	if (!(mPlayer_data->mLife < 0)) {
		for (i = 0; i < (*tmp_zako).size(); i++) {
			for (j = 0; j < (*tmp_zako)[i].mvZakoShot->size(); j++) {
				vector<ZakoShot> *tmp_zakoshot = (*tmp_zako)[i].mvZakoShot;
				for (k = 0; k < ((*tmp_zakoshot)[j].mvBullet)->size(); k++) {
					vector<Bullet> *tmp_bullet = (*tmp_zakoshot)[j].mvBullet;
					if ((*tmp_bullet)[k].mFlag) {
						if (mPlayer_data->mMuteki_flag == false) {
							if (Collision((*tmp_bullet)[k].mVec, mPlayer_data->Get_vector(), outpattern::ZAKOSHOT_PLAYER)) {

								mPlayer_data->mMuteki_flag = true;
								mPlayer_data->mCount = 0;
								mPlayer_data->mDeleteFlag = true;
								mPlayer_data->mFlag = false;
								mPlayer_data->mDeathFlag = true;
								EffectMgr::Instance()->effEnter2(mPlayer_data->Get_vector(), EffectKnd::HADOU_EFF, 0, 10, 3);
								Music::Instance()->enterSe(2);


							}
						}
					}


				}
			}

		}
	}

}

void OutMgr::outCalcPlayerShotAndBoss() {
	int i;
	for (i = 0; i < (*tmp_boss).size(); i++) {

		if ((*tmp_boss)[i].mFlag) {
			printfDx("test_outCalcPlaerShotAndBoss_in_(*tmp_boss)[i].mFlag_in_OutMgr\n");
			//ここにショットと敵のコリジョンをいれる
			for (int k = 0; k < C_BULLET_NUM; k++) {
				if (mPlayer_data->pPlayerShot->get_Bullet(k)->flag) {
					if (Collision((*tmp_boss)[i].Get_vector(),
						mPlayer_data->pPlayerShot->get_Bullet(k)->Get_vec(),
						outpattern::PLAYERSHOT_BOSS)) {
						printfDx("test_outCalcPlaerShotAndBoss_in_Collision_in_OutMgr\n");
						(*tmp_boss)[i].mHp--;
						mPlayer_data->pPlayerShot->get_Bullet(k)->flag = false;
						Music::Instance()->enterSe(3);
						if ((*tmp_boss)[i].mHp<0) {
							(*tmp_boss)[i].mDeleteFlag = true;
							(*tmp_boss)[i].mFlag = false;
							EffectMgr::Instance()->effEnter((*tmp_boss)[i].Get_vector(), EffectKnd::DELETE_EFF00);
							EffectMgr::Instance()->effEnter2((*tmp_boss)[i].Get_vector(), EffectKnd::DELETE_EFF00, 0, 4, 4);
							

						}
			
						mEnemyHit++;	
					}	
				}
			}
		}
	}
}

void OutMgr::outCalcBossShotAndPlayer() {
	int i, j, k;
	if (!(mPlayer_data->mLife < 0)) {
		for (i = 0; i < (*tmp_boss).size(); i++) {
			for (j = 0; j < (*tmp_boss)[i].mvBossShot->size(); j++) {
				vector<BossShot> *tmp_bossshot = (*tmp_boss)[i].mvBossShot;
				for (k = 0; k < ((*tmp_bossshot)[j].mvBullet)->size(); k++) {
					vector<Bullet> *tmp_bullet = (*tmp_bossshot)[j].mvBullet;
					if ((*tmp_bullet)[k].mFlag) {
						if (mPlayer_data->mMuteki_flag == false) {
							if (Collision((*tmp_bullet)[k].mVec, mPlayer_data->Get_vector(), outpattern::BOSSSHOT_PLAYER)) {

								mPlayer_data->mMuteki_flag = true;
								mPlayer_data->mCount = 0;
								mPlayer_data->mDeleteFlag = true;
								mPlayer_data->mFlag = false;
								mPlayer_data->mDeathFlag = true;
								EffectMgr::Instance()->effEnter2(mPlayer_data->Get_vector(), EffectKnd::HADOU_EFF, 0, 10, 3);
								Music::Instance()->enterSe(2);


							}
						}
					}


				}
			}

		}
	}

}

void OutMgr::outCalcPlayerAndBoss() {
	int i;
	int tmp_out = static_cast<int>(outpattern::PLAYER_BOSS);
	for (i = 0; i < (*tmp_boss).size(); i++) {

		if ((*tmp_boss)[i].mFlag) {
			if (mPlayer_data->mMuteki_flag == false) {

				if (Collision((*tmp_boss)[i].Get_vector(), mPlayer_data->Get_vector(), tmp_out)) {

					mPlayer_data->mMuteki_flag = true;
					mPlayer_data->mCount = 0;
					mPlayer_data->mDeleteFlag = true;
					mPlayer_data->mFlag = false;
					mPlayer_data->mDeathFlag = true;
					if (!(mPlayer_data->mLife < 0)) {
						EffectMgr::Instance()->effEnter2(mPlayer_data->Get_vector(), EffectKnd::HADOU_EFF, 0, 10, 3);
						Music::Instance()->enterSe(2);
					}




				}
			}
		}
	}
}
void OutMgr::Process() {
	outCalcBomb();
	outCalcPlayerAndZako();
	outCalcPlayerShotAndZako();
	outCalcZakoShotAndPlayer();
	outCalcPlayerShotAndBoss();
	outCalcBossShotAndPlayer();
	outCalcPlayerAndBoss();
	/*
	if(mEffect_flag==true){ printfDx("flag==true\n"); }
	else { printfDx("flag==false\n"); }

	if (mEffect_flag) {
		if ((0<=EffectMgr::Instance()->pEffectCircle->get_this()->get_count())&&
			(0<EffectMgr::Instance()->pEffectCircle->get_this()->get_count()<60)) {
			EffectMgr::Instance()->pEffectCircle->Process(*mPlayer_data->Get_vector(),mPlayer_data->mMuteki_flag,mPlayer_data->mMuteki_count);
			EffectMgr::Instance()->pEffectMagic->Process(*mPlayer_data->Get_vector(),mPlayer_data->mMuteki_flag,mPlayer_data->mMuteki_count);

		}
		else {
			mEffect_flag = false;
		}
	}
	if (mEffect_flag == true) { printfDx("flag==true\n"); }
	else { printfDx("flag==false\n"); }

	if (mEffect_flag_teki) {
		if ((0 <= EffectMgr::Instance()->pEffectCircle->get_this()->get_count()) &&
			(0<EffectMgr::Instance()->pEffectCircle->get_this()->get_count()<60)) {
			EffectMgr::Instance()->pEffectCircle->Process(*mPlayer_data->Get_vector(), mPlayer_data->mMuteki_flag, mPlayer_data->mMuteki_count);
			EffectMgr::Instance()->pEffectMagic->Process(*mPlayer_data->Get_vector(), mPlayer_data->mMuteki_flag, mPlayer_data->mMuteki_count);

		}
		else {
			mEffect_flag_teki = false;
		}
	}
	printfDx("effect circle %p \n", EffectMgr::Instance()->pEffectCircle);
	*/
}
bool OutMgr::Collision(const Vector2* vec_A, const Vector2* vec_B, int i) {
	double r1, r2;
	//当たり方によって半径を決める
	switch (i) {
	case outpattern::PLAYER_ZAKO:
		r1 = C_ROUND;
		r2 = ZAKO_ROUND;
		break;
	case outpattern::PLAYERSHOT_ZAKO:
		r1 = C_BULLET_ROUND;
		r2 = ZAKO_ROUND;
		break;
	case outpattern::ZAKOSHOT_PLAYER:
		r1 = ZAKO_BULLET_ROUND;
		r2 = C_ROUND;
		break;
	case outpattern::PLAYERSHOT_BOSS:
		r1 = C_BULLET_ROUND;
		r2 = BOSSROUND00;
		break;
	case outpattern::BOSSSHOT_PLAYER:
		r1 = BOSS_BULLET_ROUND;
		r2 = C_ROUND;
		break;
	case outpattern::PLAYER_BOSS:
		r1 = C_ROUND;
		r2 = BOSSROUND00;
		break;
	default:
		DxLib_End();
	}
	
	double ax = vec_A->x;
	double ay = vec_A->y;
	double bx = vec_B->x;
	double by = vec_B->y;

	double tmp = (ax - bx)*(ax - bx) + (ay - by)*(ay - by);
	double distance = sqrt(tmp);

	if (i != -1) {
		if (distance < r1+r2) {
			return true;//当たってる当たってる「当ててんのよ」
		}

		else {
			return false;
		}
	}
	

}

void OutMgr::Finalize() {
}

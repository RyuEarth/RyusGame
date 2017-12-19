#include "Boss.h"
#include "DxLib.h"
#include "Vector2.h"
#include "Player.h"
#include "BossShot.h"
#include "BossActPattern.h"
#include "Image.h"
#include "EffectMgr.h"
#include "Bullet.h"
#include "Define.h"
#include <vector>
using namespace std;



Boss::Boss(Vector2* vec,vector<Zako>* zako,int knd) {

	mPlayerVec = vec;
	mMuki = 0;
	mTip_width = 0;
	mTip_x = 0;
	mCount = 0;
	mShotCount = 0;
	mEnterMoveCount = 0;
	mvZako = zako;
	mFlag = true;
	mEnterMoveFlag = 1;
	mStartShotFlag = 0;
	mShotFlag = 0;
	mShotKnd = 0;
	mKnd = knd;
	mHp = 30;
	pBossActPattern = 0;
	mVec = new Vector2(SCREEN_X_HALF+20,-100);
	
	mvBossShot = new vector<BossShot>;

	pBossActPattern = new BossActPattern(this);
	if (!pBossActPattern) {
		printfDx("alocate error!");
		DxLib_End();
	}
}
Boss::~Boss() {
}

void Boss::Initialize() {
}


void Boss::createShot(int ShotKnd) {
	(*mvBossShot).push_back(BossShot(mVec, mPlayerVec, mvZako,ShotKnd));
}
void Boss::enterShot() {
	//�V���b�g���ǂꂾ���m�ۂ��邩�����߂�

	if (mShotFlag==1) {
		createShot(0);
		createShot(2);
		createShot(1);
		mShotFlag = 2;
	}
	
	//�����ł͂ǂ̂悤�ȃV���b�g���ɂ��邩�i�g�ݍ��킹�Ȃǁj�����߂�@

	/*
	if (mHp < 0) {
	switch (mCount) {
	case SHOT00:
	(*mvBossShot).push_back(BossShot(mVec, mPlayerVec, mvZako));
	printfDx("enterShot\n");

	case SHOT01:
	}
	}
	*/
	
}

void Boss::calcShot() {
	if(mShotFlag==2){//�V���b�g����
		int i;
		for (i = 0; i < (*mvBossShot).size(); i++) {
			if ((*mvBossShot)[i].mFlag) {
				(*mvBossShot)[i].calcShot(&(*mvBossShot)[i].mFlag);
			}
		}
		for (i = 0; i < (*mvBossShot).size(); i++) {
			if ((*mvBossShot)[i].mFlag == 0) {
				pBossShot = (*mvBossShot).begin();
				pBossShot += i;
				(*mvBossShot).erase(pBossShot);
			}
		}
		if (mFlag == 0) {//�{�X�����񂾂�
			for (int i = 0; i < (*mvBossShot).size(); i++) {
				for (int j = 0; j < (*mvBossShot)[i].mvBullet->size(); j++) {
					EffectMgr::Instance()->effEnter2((*(*mvBossShot)[i].mvBullet)[j].mVec , DELETE_EFF00, 0, 0, 1);
				}
			}
			(*mvBossShot).clear();
		}
		printfDx("test_sizeOfBossShot:%d\n", (*mvBossShot).size());
	}
	
	mShotCount++;//�V���b�g���n�܂��Ă���̎���
	

	
}
void Boss::calcEnterMove() {
	if (mEnterMoveFlag > 0) {
		mVec->y += 1.2;//���X�Ƀ{�X�����~����
		mEnterMoveCount++;
		mFlag = 1;
		if (mEnterMoveCount > 300||mVec->y>120) {
			mEnterMoveFlag = 0;
			mShotFlag = 1;
		}
	}
}
void Boss::Process() {


	mCount_motion = mCount % 560;//560�ɈӖ��͂Ȃ��Bint���I�[�o�[�t���[���N�����Ȃ��悤�ɂ��邽�߁B
	mTip_x = static_cast<int>(mCount_motion / 8) % 5;

	calcEnterMove();
	pBossActPattern->process();

	/*
	���E�̃{�X�̃`�b�v���ł�����������邩��
	if (pBossActPattern->mVx < -1) {
	mMuki = 0;
	}
	else if (pBossActPattern->mVx > 1) {
	mMuki = 2;
	}
	else {
	mMuki = 1;
	}
	*/
		
	enterShot();//�V���b�g�I�u�W�F�N�g�̐����Ɠo�^
	
	calcShot();
	mCount++;
	
}
void Boss::Draw() {
	if (mFlag) {
		DrawRotaGraph(mVec->x, mVec->y, 1.0, 0.0, (Image::Instance()->getKaranChip()[mMuki*mTip_width + mTip_x]), true);
	}
	int i;
	for (i = 0; i < (*mvBossShot).size(); i++) {
		(*mvBossShot)[i].draw();
	}

}
void Boss::Finalize() {
}
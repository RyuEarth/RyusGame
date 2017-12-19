#include "BossShot.h"
#include "Vector2.h"
#include "Bullet.h"
#include "Define.h"
#include "Image.h"
#include "Player.h"
#include "DxLib.h"
#include "Function.h"
#include "math.h"
#include "Music.h"
#include "EffectMgr.h"
#include <vector>



BossShot::BossShot(Vector2 *vec,
	const Vector2* playerVec,vector<Zako>* zako,int ShotKnd) {

	
	mPlayerVec = playerVec;
	mvBullet = new vector<Bullet>;
	mvZako = zako;
	mVec = new Vector2;
	mVec = vec;
	mKnd = ShotKnd;
	mCount = 0;
	mFlag = 1;


}

BossShot::~BossShot() {
}

void BossShot::enterShotConductor() {
	switch (mKnd) {
	case 0:
		enterPattern00();
		break;
	case 1:
		enterPattern01();
		break;
	case 2:
		enterPattern02();
		break;
	case 3:
		enterPattern03();
		break;
	default:
		
		break;
	}
}
//引数分のオブジェクトを生成
void BossShot::createBullet(int ObjNum) {
	
	for (int i = 0; i < ObjNum; i++) {
		(*mvBullet).push_back(Bullet(mVec));
	}
}
//登録部
void BossShot::enterPattern00(){
	int count = mCount % 120;
	if (count % 10 == 0 && count < 60) {
		createBullet(10);
	}
	for (int i = 0; i < (*mvBullet).size(); i++) {
		if ((*mvBullet)[i].mCount ==0) {
			(*mvBullet)[i].mAngle = PI2 / 10*i;
			(*mvBullet)[i].mCount = 0;
			(*mvBullet)[i].mFlag = 1;
			(*mvBullet)[i].mTill = 0;
			(*mvBullet)[i].mVec->x = mVec->x;
			(*mvBullet)[i].mVec->y = mVec->y;
			(*mvBullet)[i].mVel = 2.0;
			(*mvBullet)[i].mCol = 2;
			(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle;
			(*mvBullet)[i].mKnd = 1;
		}
		else if((*mvBullet)[i].mCount < 60) {
			(*mvBullet)[i].mVel += 0.01;
			(*mvBullet)[i].mAngle -= 0.02;
			(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle;
		}
		else {
			(*mvBullet)[i].mVel += 0.01;
			(*mvBullet)[i].mAngle += 0.02;
			(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle;
		}
		(*mvBullet)[i].mCount++;
	}
	
}
void BossShot::enterPattern01() {
	int count = mCount % 120;
	if (count % 10 == 0 && count < 60) {
		createBullet(10);
	}
	for (int i = 0; i < (*mvBullet).size(); i++) {
		if ((*mvBullet)[i].mCount == 0) {
			(*mvBullet)[i].mAngle = PI2 / 10 * i;
			(*mvBullet)[i].mCount = 0;
			(*mvBullet)[i].mFlag = 1;
			(*mvBullet)[i].mTill = 0;
			(*mvBullet)[i].mVec->x = mVec->x;
			(*mvBullet)[i].mVec->y = mVec->y;
			(*mvBullet)[i].mVel = 2.0;
			(*mvBullet)[i].mCol = 3;
			(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle;
			(*mvBullet)[i].mKnd = 1;
		}else {
			(*mvBullet)[i].mVel += 0.01;
			(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle;
		}
		(*mvBullet)[i].mCount++;
	}

}
void BossShot::enterPattern02() {
	int count = mCount % 120;
	if (count % 10 == 0 && count > 60) {
		createBullet(4);
	}
	for (int i = 0; i < (*mvBullet).size(); i++) {
		if ((*mvBullet)[i].mCount == 0) {
			(*mvBullet)[i].mAngle =getAngle(*mPlayerVec,*mVec)+ PI2 / 4 * i;
			(*mvBullet)[i].mCount = 0;
			(*mvBullet)[i].mFlag = 1;
			(*mvBullet)[i].mTill = 0;
			(*mvBullet)[i].mVec->x = mVec->x;
			(*mvBullet)[i].mVec->y = mVec->y;
			(*mvBullet)[i].mVel = 3.0;
			(*mvBullet)[i].mCol = 0;
			(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle;
			(*mvBullet)[i].mKnd = 1;
		}
		else {
			(*mvBullet)[i].mVel += 0.01;
			(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle;
		}
		(*mvBullet)[i].mCount++;
	}

}
void BossShot::enterPattern03() {
	int count = mCount % 120;
	if (count % 10 == 0 && count < 60) {
		createBullet(10);
	}
	for (int i = 0; i < (*mvBullet).size(); i++) {
		if ((*mvBullet)[i].mCount == 0) {
			(*mvBullet)[i].mAngle = PI2 / 10 * i;
			(*mvBullet)[i].mCount = 0;
			(*mvBullet)[i].mFlag = 1;
			(*mvBullet)[i].mTill = 0;
			(*mvBullet)[i].mVec->x = mVec->x;
			(*mvBullet)[i].mVec->y = mVec->y;
			(*mvBullet)[i].mVel = 2.0;
			(*mvBullet)[i].mCol = 3;
			(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle;
			(*mvBullet)[i].mKnd = 1;
		}
		else {
			(*mvBullet)[i].mVel += 0.01;
			(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle;
		}
		(*mvBullet)[i].mCount++;
	}

}
void BossShot::calcShot(int *flag) {
	

	//登録部の分岐
	enterShotConductor();
	//弾の計算部
	int i;
	for (i = 0; i < (*mvBullet).size(); i++) {
		if ((*mvBullet)[i].mFlag) {
			(*mvBullet)[i].mVec->x += cos((*mvBullet)[i].mAngle)*(*mvBullet)[i].mVel;
			(*mvBullet)[i].mVec->y += sin((*mvBullet)[i].mAngle)*(*mvBullet)[i].mVel;
			(*mvBullet)[i].mCount++;
			if ((*mvBullet)[i].mVec->x<SCREEN_X_MIN - 50 || (*mvBullet)[i].mVec->x>SCREEN_X_MAX + 50 ||
				(*mvBullet)[i].mVec->y<SCREEN_Y_MIN - 50 || (*mvBullet)[i].mVec->y>SCREEN_Y_MAX + 50) {
				if ((*mvBullet)[i].mCount >(*mvBullet)[i].mTill) {
					(*mvBullet)[i].mFlag = 0;
				}
			}
		}
	}
	for (i = 0; i < (*mvBullet).size(); i++) {
		if ((*mvBullet)[i].mFlag == 0) {
			pBullet = (*mvBullet).begin();
			pBullet += i;
			EffectMgr::Instance()->effEnter2((*mvBullet)[i].mVec, DELETE_EFF00, 0, 0, 1);
			(*mvBullet).erase(pBullet);
		}
	}
	if ((*mvBullet).empty()&&mCount>2000) {//弾がすべてないかつショット時間内だったら
		*flag = 0;
		//thisを殺す信号を送る
	}
	mCount++;//ショットカウントを増やす
}


void BossShot::draw() {
	for (int i = 0; i < (*mvBullet).size(); i++) {
		DrawRotaGraph((*mvBullet)[i].mVec->x, (*mvBullet)[i].mVec->y,
			1.0, (*mvBullet)[i].mBulletAngle+PI_D2, (Image::Instance()->getBulletImage((*mvBullet)[i].mKnd))[(*mvBullet)[i].mCol], true);

	}

}
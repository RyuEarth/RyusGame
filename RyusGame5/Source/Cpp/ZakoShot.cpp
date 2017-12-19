#include "ZakoShot.h"
#include "Bullet.h"
#include "Vector2.h"
#include "Define.h"
#include "Image.h"
#include "Player.h"
#include "DxLib.h"
#include "math.h"
#include "Music.h"
#include "EffectMgr.h"
#include <vector>
using namespace std;

ZakoShot::ZakoShot(Vector2 *vec ,const t_enemy_order& pZako_data,
	const Vector2* playerVec) {
	
	mPlayerVec = playerVec;
	mvBullet = new vector<Bullet>;
	mVec = new Vector2;
	mVec = vec;
	mKnd = pZako_data.blknd;
	mCount = 0;

	mFlag = 1;
	pOrder = &pZako_data;
	

}

ZakoShot::~ZakoShot() {
}

void ZakoShot::enterBullet() {
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
	case 4:
		enterPattern04();
		break;
	case 5:
		enterPattern05();
		break;
	default:
		
		break;
	}
}
//“o˜^‚ÌÛ‚É‰ŠúˆÊ’u‚â“o˜^’e”‚ðÝ’è
void ZakoShot::enterPattern00() {
	if (mCount == 0) {
		printfDx("enterPattern00\n");
		(*mvBullet).push_back(Bullet(mVec, *pOrder));
		(*mvBullet).back().mAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec);

		(*mvBullet).back().mCount = 0;
		(*mvBullet).back().mFlag = 1;
		(*mvBullet).back().mTill = 0;
		(*mvBullet).back().mVec->x = mVec->x;
		(*mvBullet).back().mVec->y = mVec->y;
		(*mvBullet).back().mVel = 4.0;
		(*mvBullet).back().mBulletAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec) + PI_D2;
		Music::Instance()->enterSe(0);
		//’Ç‰Á‚Å“o˜^‚·‚é(*mvBullet).back().mAngle=1/60;“™
	}

}

void ZakoShot::enterPattern01() {
	if (mCount == 0) {
		for (int i = 0; i < 10; i++) {
			(*mvBullet).push_back(Bullet(mVec, *pOrder));
			(*mvBullet).back().mAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec) + i*PI2 / 10;

			(*mvBullet).back().mCount = 0;
			(*mvBullet).back().mFlag = 1;
			(*mvBullet).back().mTill = 0;
			(*mvBullet).back().mVec->x = mVec->x;
			(*mvBullet).back().mVec->y = mVec->y;
			(*mvBullet).back().mVel = 4.0;
			(*mvBullet).back().mBulletAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec) + i*PI2 / 10 + PI_D2;
		}
		Music::Instance()->enterSe(0);

	}

	
}
void ZakoShot::enterPattern02() {
	if (mCount == 0) {
		for (int i = 0; i < 10; i++) {
			(*mvBullet).push_back(Bullet(mVec, *pOrder));
			(*mvBullet).back().mAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec) + i*PI2 / 10;

			(*mvBullet).back().mCount = 0;
			(*mvBullet).back().mFlag = 1;

			(*mvBullet).back().mTill = 0;
			(*mvBullet).back().mVec->x = mVec->x;
			(*mvBullet).back().mVec->y = mVec->y;
			(*mvBullet).back().mVel = 4.0;
			(*mvBullet).back().mBulletAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec) + i*PI2 / 10 + PI_D2;
		}
		Music::Instance()->enterSe(0);

	}

}
void ZakoShot::enterPattern03() {
	if (mCount == 0) {
		for (int i = 0; i < 10; i++) {
			(*mvBullet).push_back(Bullet(mVec, *pOrder));
			(*mvBullet).back().mAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec) + i*PI2 / 10;

			(*mvBullet).back().mCount = 0;
			(*mvBullet).back().mFlag = 1;

			(*mvBullet).back().mTill = 0;
			(*mvBullet).back().mVec->x = mVec->x;
			(*mvBullet).back().mVec->y = mVec->y;
			(*mvBullet).back().mVel = 4.0;
			(*mvBullet).back().mBulletAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec) + i*PI2 / 10 + PI_D2;
		}
	}

}
void ZakoShot::enterPattern04() {
	if (mCount == 0) {
		for (int i = 0; i < 10; i++) {
			(*mvBullet).push_back(Bullet(mVec, *pOrder));
			(*mvBullet).back().mAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec) + i*PI2 / 10;
	
			(*mvBullet).back().mCount = 0;
			(*mvBullet).back().mFlag = 1;
			(*mvBullet).back().mKnd = 0;
			(*mvBullet).back().mTill = 0;
			(*mvBullet).back().mVec->x = mVec->x;
			(*mvBullet).back().mVec->y = mVec->y;
			(*mvBullet).back().mVel = 4.0;
			(*mvBullet).back().mBulletAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec) + i*PI2 / 10 + PI_D2;
		}
	}

}
void ZakoShot::enterPattern05() {
	if (mCount == 0) {
		for (int i = 0; i < 10; i++) {
			(*mvBullet).push_back(Bullet(mVec, *pOrder));
			(*mvBullet).back().mAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec) + i*PI2 / 10;

			(*mvBullet).back().mCount = 0;
			(*mvBullet).back().mFlag = 1;
			(*mvBullet).back().mKnd = 0;
			(*mvBullet).back().mTill = 0;
			(*mvBullet).back().mVec->x = mVec->x;
			(*mvBullet).back().mVec->y = mVec->y;
			(*mvBullet).back().mVel = 4.0;
			(*mvBullet).back().mBulletAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec) + i*PI2 / 10 + PI_D2;
		}
	}

}
double ZakoShot::getPlayerAndZakoAngle(const Vector2* vec) {
	Vector2 *tmp_Vec = new Vector2;
	tmp_Vec->x = mPlayerVec->x - vec->x;
	tmp_Vec->y = mPlayerVec->y - vec->y;
	return atan2(tmp_Vec->y, tmp_Vec->x);

}

double ZakoShot::getDistance(const Vector2* vec) {
	double d;
	double tx=vec->x - mPlayerVec->x;
	double ty = vec->y - mPlayerVec->y;

	d = sqrt(tx*tx+ty*ty);
	return d;
}

void ZakoShot::calcShotConductor() {
	switch (mKnd) {
	case 0:
		calcPattern00();
		break;
	case 1:
		calcPattern01();
		break;

	case 2:
		calcPattern02();
		break;
	case 3:
		calcPattern03();
		break;
	case 4:
		calcPattern04();
		break;
	case 5:
		calcPattern05();
		break;
	default:

		break;
	}
}
void ZakoShot::calcPattern00() {
	for (int i = 0; i < (*mvBullet).size(); i++) {
		if (mCount < 300) {
		(*mvBullet)[i].mVel = getDistance((*mvBullet)[i].mVec) / 50.f;
		(*mvBullet)[i].mAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec);
		(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle + PI_D2;
		}
		else {
			(*mvBullet)[i].mFlag = 0;
			EffectMgr::Instance()->effEnter2((*mvBullet)[i].mVec, DELETE_EFF00, 0, 0, 1);
		}
	}
}
void ZakoShot::calcPattern01() {
	for (int i = 0; i < (*mvBullet).size(); i++) {
		(*mvBullet)[i].mVel -= 0.05;
		(*mvBullet)[i].mAngle += 0.01;
		(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle + PI_D2;
	}
}
void ZakoShot::calcPattern02() {
	for (int i = 0; i < (*mvBullet).size(); i++) {
		(*mvBullet)[i].mVel -= 0.1; 
		(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle + PI_D2;
	}
}
void ZakoShot::calcPattern03() {
	for (int i = 0; i < (*mvBullet).size(); i++) {
		(*mvBullet)[i].mVel += 0.1;
		(*mvBullet)[i].mAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec) / 4.0;
		(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle + PI_D2;
	}
}
void ZakoShot::calcPattern04() {
	for (int i = 0; i < (*mvBullet).size(); i++) {
		(*mvBullet)[i].mVel += 0.1;
		(*mvBullet)[i].mAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec) / 4.0;
		(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle + PI_D2;
	}
}
void ZakoShot::calcPattern05() {
	for (int i = 0; i < (*mvBullet).size(); i++) {
		(*mvBullet)[i].mVel += 0.1;
		(*mvBullet)[i].mAngle = getPlayerAndZakoAngle((*mvBullet).back().mVec) / 4.0;
		(*mvBullet)[i].mBulletAngle = (*mvBullet)[i].mAngle + PI_D2;
	}
}
void ZakoShot::calcShot(int *flag,int zakoflag) {
	if(zakoflag)enterBullet();


	calcShotConductor();
	int i;
	for (i = 0; i < (*mvBullet).size(); i++) {
		if ((*mvBullet)[i].mFlag ){
			(*mvBullet)[i].mVec->x += cos((*mvBullet)[i].mAngle)*(*mvBullet)[i].mVel;
			(*mvBullet)[i].mVec->y += sin((*mvBullet)[i].mAngle)*(*mvBullet)[i].mVel;
			(*mvBullet)[i].mCount++;
			if ((*mvBullet)[i].mVec->x<SCREEN_X_MIN - 50 || (*mvBullet)[i].mVec->x>SCREEN_X_MAX + 50 ||
				(*mvBullet)[i].mVec->y<SCREEN_Y_MIN - 50 || (*mvBullet)[i].mVec->y>SCREEN_Y_MAX + 50) {
				if ((*mvBullet)[i].mCount > (*mvBullet)[i].mTill) {
					(*mvBullet)[i].mFlag = 0;
				}
			}
		}
	}
	for (i = 0; i < (*mvBullet).size(); i++) {
		if ((*mvBullet)[i].mFlag == 0) {
			pBullet = (*mvBullet).begin();
			pBullet+=i;
			(*mvBullet).erase(pBullet);
		}
	}
	if ((*mvBullet).empty()) {//’e‚ª‚·‚×‚Ä‚È‚¢‚Ì‚È‚ç
		*flag = 0;
	}
	mCount++;//ƒVƒ‡ƒbƒgƒJƒEƒ“ƒg‚ð‘‚â‚·
}


void ZakoShot::draw() {
	for (int i = 0; i < (*mvBullet).size(); i++) {
		DrawRotaGraph((*mvBullet)[i].mVec->x, (*mvBullet)[i].mVec->y,
			1.0, (*mvBullet)[i].mBulletAngle, (Image::Instance()->getBulletImage((*mvBullet)[i].mKnd))[(*mvBullet)[i].mCol], true);

	}

}
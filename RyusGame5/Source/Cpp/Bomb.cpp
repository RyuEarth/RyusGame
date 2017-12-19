#include "Bomb.h"
#include "Vector2.h"
#include "Image.h"
#include "EffectMgr.h"
#include "Define.h"

Bomb::Bomb(Vector2 *vec) {
	mCount = 0;
	mKnd = 0;
	mFlag = 0;
	mTill = 0;
	mAngle = 0;
	mBulletAngle = 0;
	mVel = 0;
	mVec = new Vector2;
	*mVec = *vec;
}

Bomb::~Bomb(){}

void Bomb::conductor() {

}
void Bomb::enterBomb() {
	if (mFlag == 0){
		mFlag = 1;
		mCount = 0;
		EffectMgr::Instance()->effEnter2(&Vector2(250, 300), EffectKnd::CHARA_EFF00, 60, 1, 1);
		EffectMgr::Instance()->effEnter2(mVec, EffectKnd::DELETE_EFF01, 0, 2, 3);
	}
}

void Bomb::calc() {
	if (mFlag) {
		mCount++;
		
	}

}
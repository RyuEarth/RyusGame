#include "Bullet.h"
#include "Vector2.h"
#include "EffectMgr.h"
#include "Define.h"
Bullet::Bullet(Vector2 *vec,const t_enemy_order& pOrder) {
	mVec = new Vector2;
	*mVec = *vec;
	mCol = pOrder.col;
	mKnd = pOrder.blknd2;
	mFlag = 1;
	mCount = 0;
	mAngle = 0;
	mVel = 0;
}

Bullet::Bullet(Vector2 *vec) {
	mVec = new Vector2;
	*mVec = *vec;
	mCol = 0;
	mKnd = 0;
	mFlag = 1;
	mCount = 0;
	mAngle = 0;
	mVel = 0;
}
Bullet::~Bullet(){

}
#ifndef INCLUDED_BULLET_H
#define INCLUDED_BULLET_H

#include "Struct.h"
class Vector2;

class Bullet{
public:
	Bullet(Vector2 *vec,const t_enemy_order& pOrder);
	Bullet(Vector2 *vec);
	~Bullet();

	int mCol,mCount,mKnd,mFlag,mTill;
	//ショットカラー,カウント、種類、フラグ、まだ消えない時間
	double mAngle,mBulletAngle,mVel;
	//進む角度,弾自体の角度,速度
	Vector2 *mVec;

private:

};

#endif
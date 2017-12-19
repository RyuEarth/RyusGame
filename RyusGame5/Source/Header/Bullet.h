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
	//�V���b�g�J���[,�J�E���g�A��ށA�t���O�A�܂������Ȃ�����
	double mAngle,mBulletAngle,mVel;
	//�i�ފp�x,�e���̂̊p�x,���x
	Vector2 *mVec;

private:

};

#endif
#ifndef INCLUDED_BOMB_H
#define INCLUDED_BOMB_H

class Vector2;
class Bomb {
public:
	Bomb(Vector2 *vec);
	~Bomb();

	void enterBomb();
	void conductor();
	void calc();
	int mCount, mKnd, mFlag, mTill;
	//�J�E���g�A��ށA�t���O�A�܂������Ȃ�����
	double mAngle, mBulletAngle, mVel;
	//�i�ފp�x,�e���̂̊p�x,���x
	Vector2 *mVec;//player�̃x�N�^�[
	
};

#endif
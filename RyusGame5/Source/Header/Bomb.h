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
	//カウント、種類、フラグ、まだ消えない時間
	double mAngle, mBulletAngle, mVel;
	//進む角度,弾自体の角度,速度
	Vector2 *mVec;//playerのベクター
	
};

#endif
#ifndef INCLUDED_BOSS_SHOT_H
#define INCLUDED_BOSS_SHOT_H

#include "Enemy.h"
class Vector2;
class Bullet;
class BossShot{
public:
	BossShot(Vector2* vec,const Vector2* playerVec,vector<Zako>*,int ShotKnd);
	~BossShot();

	std::vector<Bullet> *mvBullet;
	std::vector<Bullet>::iterator pBullet;
	int mCount, mKnd, mFlag;

	Vector2 *mVec;
	const t_enemy_order *pOrder;//代わりにボスのオーダーを得る
	
	void calcShot(int *flag);
	void draw();

private:
	const Vector2* mPlayerVec;
	vector<Zako> *mvZako;
	void enterShotConductor();
	void createBullet(int ObjNum);



	void enterPattern00();
	void enterPattern01();
	void enterPattern02();
	void enterPattern03();

};

#endif

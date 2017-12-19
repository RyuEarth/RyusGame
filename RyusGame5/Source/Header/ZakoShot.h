#ifndef INCLUDED_ZAKO_SHOT_H
#define INCLUDED_ZAKO_SHOT_H

#include "Struct.h"
#include <vector>
class Bullet;
class Vector2;
class ZakoShot {
public:
	ZakoShot(Vector2* vec,const t_enemy_order& pZako_data,
		const Vector2* playerVec);
	~ZakoShot();
	
	std::vector<Bullet> *mvBullet;
	std::vector<Bullet>::iterator pBullet;
	int mCount,mKnd,mFlag;
	
	Vector2 *mVec;
	const t_enemy_order *pOrder;
	void enterBullet();
	void calcShot(int *flag,int zakoflag);
	void draw();

private:
	const Vector2* mPlayerVec;
	double getPlayerAndZakoAngle(const Vector2* vec);
	double getDistance(const Vector2* vec);
	void calcShotConductor();
	void enterPattern00();
	void enterPattern01();
	void enterPattern02();
	void enterPattern03();
	void enterPattern04();
	void enterPattern05();
	
	void calcPattern00();
	void calcPattern01();
	void calcPattern02();
	void calcPattern03();
	void calcPattern04();
	void calcPattern05();
};

#endif

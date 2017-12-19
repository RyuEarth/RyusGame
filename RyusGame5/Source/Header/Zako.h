#ifndef INCLUDED_ZAKO_H
#define INCLUDED_ZAKO_H

#include "Enemy.h"//Enemy.hでStructをinclude済み
#include <vector>


class ZakoShot;
class PlayerShot;
class ZakoActPattern;
class Vector2;
class Zako {
public:
	Zako(const t_enemy_order&,const int*,Vector2*);
	~Zako();

	void Initialize();
	void Process();
	void Draw();
	void Finalize();

	const t_enemy_order* pZako_data;


	const int *mImage;


	int mFlag;
	int mDeleteFlag;
	int mShotFlag;

	std::vector<ZakoShot> *mvZakoShot;
	std::vector<ZakoShot>::iterator pZakoShot;
	Vector2* Get_vector() {//現在のベクターを返す
		return mVec;
	}

private:



	void enterShot();
	void calcShot();

	ZakoActPattern* pZakoActPattern;

	PlayerShot* pPlayerShot;
	
	Vector2* mPlayerVec;
	Vector2* mVec;

	int mCount_motion;
	int mMuki;
	int mTip_width;
	int mTip_x;
	int mCount;//flagが立つ前からカウント
	int mZako_in_count;//フラグが立ってから

};

#endif
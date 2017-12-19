#ifndef INCLUDED_BOSS_H
#define INCLUDED_BOSS_H

#include "Enemy.h"//Enemy.hでStructをinclude済み
#include <vector>
using namespace std;

class BossShot;
class PlayerShot;
class BossActPattern;
class Vector2;
class Boss{
public:
	Boss(Vector2*, vector<Zako>*, int knd);//playerのベクター,雑魚
	~Boss();

	void Initialize();
	void Process();
	void Draw();
	void Finalize();

	const t_enemy_order* pZako_data;


	const int *mImage;
	double x, y, sp;
	//描画フラグ
	int mFlag;
	//登録時移動フラグ
	int mEnterMoveFlag;
	//ショット開始フラグ
	int mStartShotFlag;
	//消滅フラグ
	int mDeleteFlag;
	//ショットフラグ
	int mShotFlag;
	//種類
	int mKnd;
	//最大HP
	int mHp;
	vector<BossShot> *mvBossShot;
	vector<BossShot>::iterator pBossShot;
	vector<Zako> *mvZako;
	Vector2* Get_vector() {//現在のベクターを返す
		return mVec;
	}

private:
	/*
	クラス内でenumを宣言してもcpp内で使えない(switchなど)
	enum ShotKnd {
		KND00,
		KND01,
		KND02,
		KND03
	};
	enum ShotCount{
		SHOT00=500,
		SHOT01=600,
		SHOT02=700,
		
	};
	*/
	void calcEnterMove();
	void createShot(int ShotKnd);
	void enterShot();
	void calcShot();

	BossActPattern* pBossActPattern;

	PlayerShot* pPlayerShot;

	Vector2* mPlayerVec;
	Vector2* mVec;

	int mCount_motion;
	int mMuki;
	int mActKnd;
	int mTip_width;
	int mTip_x;
	int mCount;
	int mEnterMoveCount;
	int mShotCount;
	int mShotKnd;
};
#endif
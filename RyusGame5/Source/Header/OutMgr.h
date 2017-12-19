#ifndef INCLUDED_OUT_MGR_H
#define INCLUDED_OUT_MGR_H

#include <vector>
using namespace std;
class Enemy;
class Boss;
class Player;
class Zako;
class Vector2;


class OutMgr {
public:
	OutMgr();
	~OutMgr();
	void Initialize();
	void Process();
	void Finalize();


	Enemy* mEnemy_data;//ìGÇÃÇ¢ÇÎÇ¢ÇÎÇ»ÉfÅ[É^
	int mEnemy_num;
	int mEnemyHit;
	int mBossHitFlag;
	int mBombNum;
	Player* mPlayer_data;


private:

	bool mBombFlag;
	int mBombCount;
	
	void outCalcPlayerAndZako();
	void outCalcPlayerShotAndZako();
	void outCalcZakoShotAndPlayer();
	void outCalcPlayerShotAndBoss();
	void outCalcBossShotAndPlayer();
	void outCalcPlayerAndBoss();
	void outCalcBomb();

	vector<Zako> *tmp_zako;
	vector<Boss> *tmp_boss;
	bool mEffect_flag;
	bool mEffect_flag_teki;

	bool Collision(const Vector2*,const Vector2*,int);
};

#endif
#ifndef INCLUDED_ENEMY_H
#define INCLUDED_ENEMY_H

#include "Struct.h"
#include <vector>
using namespace std;
class Zako;
class BaseChara;
class Player;
class Boss;
class GameMgr;
class Enemy{
public:

	Enemy(Player* player, GameMgr* gamemgr);
	~Enemy();

	void Initialize();
	void Process();
	void Draw();
	void Finalize();

	void Load_story();
	int Get_enemy_num() {
		return enemy_num;
	}
	vector<Zako>& Get_zako() {
		return *mvZako;
	}
	vector<Boss>& Get_boss() {
		return *mvBoss;
	}
	
	int Image_zako[9];

private:
	Player *pPlayer;
	GameMgr *mGameMgr;
	int  enemy_num;
	t_enemy_order enemy_order[100];


	vector<Zako> *mvZako;
	vector<Boss> *mvBoss;
	void Enter_zako(const int&);
	void Search_zako();
	void bossMgr(int boss_knd);
	int mZakoState;
	int tmp;
	
};

#endif
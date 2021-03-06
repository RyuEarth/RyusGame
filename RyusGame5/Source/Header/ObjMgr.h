#ifndef INCLUDED_OBJ_MGR_H
#define INCLUDED_OBJ_MGR_H

#include "Struct.h"
#include "OutMgr.h"
#include <vector>
class Motion;
class EffectMgr;
class Player;
class Enemy;
class GameMgr;

class ObjMgr {
public:

	ObjMgr();
	ObjMgr(GameMgr* obj);
	~ObjMgr();
	void Initialize();
	void Process();
	void Draw();
	void Finalize();

	//Playerのvector入れ替え関数




	Enemy* pEnemy;
	Player* pPlayer;

	OutMgr* pOutMgr;
private:
	void Get_enemy();
	void Get_player();
	GameMgr* mGameMgr;
	Motion* pMotion;
	
	Vector2* mPlayerVec;
	EffectMgr* Effect_circle;
};

#endif

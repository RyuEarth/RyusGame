#include "ObjMgr.h"
#include "OutMgr.h"
#include "Enemy.h"
#include "Player.h"
#include "DxLib.h"
#include "EffectMgr.h"
#include "Image.h"
#include "Music.h"

ObjMgr::ObjMgr() {


	pOutMgr = 0;
	pEnemy = 0;
	pPlayer = 0;
	pMotion = 0;


}
ObjMgr::ObjMgr(GameMgr* obj) {


	pOutMgr = 0;
	pEnemy = 0;
	pPlayer = 0;
	pMotion = 0;
	mGameMgr = obj;

}
ObjMgr::~ObjMgr() {
}

void ObjMgr::Initialize() {

	
	pPlayer = new Player;
	pEnemy = new Enemy(pPlayer,mGameMgr);
	pOutMgr = new OutMgr;

	if (!(pOutMgr&&pEnemy&&pPlayer)) {
		printfDx("memory error");
		DxLib_End();
	}


	Get_enemy();
	Get_player();

	pEnemy->Initialize();
	pPlayer->Initialize();
	pOutMgr->Initialize();
}

void ObjMgr::Get_enemy() {
	pOutMgr->mEnemy_data = pEnemy;
}

void ObjMgr::Get_player() {
	pOutMgr->mPlayer_data = pPlayer;
}
void ObjMgr::Process() {
	pEnemy->Process();

	pPlayer->Process();

	pOutMgr->Process();
	EffectMgr::Instance()->effEnterConductor();
	EffectMgr::Instance()->effCalc();

	//‰¹ŠyÄ¶
	Music::Instance()->playMusic();

}

void ObjMgr::Draw() {
	pEnemy->Draw();
	pPlayer->Draw();
	EffectMgr::Instance()->Draw();
}

void ObjMgr::Finalize() {
	delete pEnemy;
	delete pPlayer;
	delete pOutMgr;

	pEnemy = 0;
	pPlayer = 0;
	pOutMgr = 0;

}

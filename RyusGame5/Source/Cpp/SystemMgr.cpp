#include "Dxlib.h"
#include "GameMgr.h"
#include "SystemMgr.h"
SystemMgr::SystemMgr() {

}

SystemMgr::~SystemMgr() {

}


bool SystemMgr::Initialize() {
	pGameMgr = new GameMgr;
	if (pGameMgr) {
		pGameMgr->Initialize();
		return true;
	}

}

void SystemMgr::Finalize() {
}

void SystemMgr::MainLoop() {
	int t = 0;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !clsDx()) {

		pGameMgr->Process();				//ƒQ[ƒ€ˆ—

		pGameMgr->Draw();						//ƒQ[ƒ€•`‰æ
	}
}




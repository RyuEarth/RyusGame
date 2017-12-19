#include "Dxlib.h"
#include "GameMgr.h"
#include "SystemMgr.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	SystemMgr* pSystemMgr=new SystemMgr;
	if (pSystemMgr->Initialize()) {
		pSystemMgr->MainLoop();
	}
	
	delete pSystemMgr;
	pSystemMgr = 0;
	return 0;

}
#include "Dxlib.h"
#include "SystemMgr.h"

SystemMgr* pSystemMgr;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	if (pSystemMgr==NULL) {
		pSystemMgr = new SystemMgr;
	}
	pSystemMgr->Process();
	return 0;
}
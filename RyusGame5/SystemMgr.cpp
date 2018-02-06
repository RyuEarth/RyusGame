#include "SystemMgr.h"
#include "Load.h"
#include "Draw.h"
#include "ObjMgr.h"
#include "Music.h"

SystemMgr::SystemMgr() {	
	pLoad = new Load();
	pDraw = new Draw();
	pMusic = new Music();
	pObjMgr = new ObjMgr();
}

SystemMgr::Process() {
	pObjMgr->Process();
	pDrawMgr->Process();
	pMusicMgr->Process();

}
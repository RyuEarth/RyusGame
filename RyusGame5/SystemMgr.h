#pragma once

class SystemMgr {
public:
	SystemMgr();
	~SystemMgr();
	void Process();
private:
	ObjMgr* pObjMgr;
	LoadMgr* pLoadMgr;
	Music* pMusic;
	Draw* pDraw;
};
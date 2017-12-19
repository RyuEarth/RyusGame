#ifndef INCLUDED_SYSTEM_MGR_H
#define INCLUDED_SYSTEM_MGR_H

class GameMgr;

class SystemMgr {
public:
	SystemMgr();
	~SystemMgr();
	bool Initialize();
	void Process();
	void Finalize();
	void MainLoop();

private:
	GameMgr* pGameMgr;

};
#endif
#ifndef INCLUDED_GAME_MGR_H
#define INCLUDED_GAME_MGR_H

class Board;
class Background;
class ObjMgr;
class Vector2;
class GameMgr {
public:
	GameMgr();
	~GameMgr();
	void Initialize();
	void Process();
	void Draw();
	void Finalize();

	int mStageCount;
	int mStageCountGoFlag;
private:
	Vector2 *mMouseVec;
	Board* pBoard;
	Background* pBackground;
	ObjMgr* pObjMgr;

};
#endif
#ifndef INCLUDED_BOARD_H
#define INCLUDED_BOARD_H
class ObjMgr;
class Player;
class Board{
public:
	Board(const ObjMgr& objmgr);
	~Board();

	void Initialize();
	void Process();
	void Draw();
	void Finalize();
private:
	int Image[4];
	const ObjMgr *pObjMgr;
	int mCount;
};

#endif

#include "Board.h"
#include "ObjMgr.h"
#include "Player.h"
#include "Image.h"
#include "Function.h"
#include "Vector2.h"
#include "Dxlib.h"
Board::Board(const ObjMgr& objmgr) {

	/*
	Image[0] = LoadGraph("Image/board_tate1.png");//Œã‚Å‹L“ü
	Image[1] = LoadGraph("Image/board_yoko1.png");
	Image[2] = LoadGraph("Image/board_yoko2.png");
	Image[3] = LoadGraph("Image/board_main1.png");

	*/
	Image[0] = LoadGraph("Image/bye_our_world.png");

	pObjMgr = &objmgr;
	mCount = 0;
}

Board::~Board() {
}

void Board::Initialize() {

}

void Board::Process() {
	mCount++;
}

void Board::Draw() {
	/*
	DrawGraph(0, 16, Image[0], true);
	DrawGraph(0, 0, Image[1], true);
	DrawGraph(0, 464, Image[2], true);
	DrawGraph(416, 0, Image[3], true);
	*/
	DrawGraph(0, 0, Image[0], true);

	DrawFormatString(520,60, GetColor(255, 255, 255), "%d",pObjMgr->pOutMgr->mEnemyHit*10 );
	for (int i = 0; i < pObjMgr->pPlayer->mLife; i++) {
		DrawAnimation(Vector2(520 + 25 * i, 93), 3, 20, 0, Image::Instance()->getZankiChip(),mCount, 1.0, 0);
		
	}
	for (int i = 0; i < pObjMgr->pOutMgr->mBombNum; i++) {
		DrawAnimation(Vector2(520 + 25 * i, 135), 3, 20, 0, Image::Instance()->getBombChip(), mCount, 1.0, 0);
	}
}

void Board::Finalize() {
}



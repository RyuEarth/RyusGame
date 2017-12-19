#include "Dxlib.h"
#include "GameMgr.h"
#include "Background.h"
#include "Board.h"
#include "Image.h"
#include "Music.h"
#include "EffectMgr.h"
#include "Player.h"
#include "Enemy.h"
#include "Key.h"
#include "ObjMgr.h"
#include "Vector2.h"
#include "Define.h"

GameMgr::GameMgr() {
	pBoard = 0;
	pBackground = 0;
	pObjMgr = 0;
	mStageCount = 0;
	mStageCountGoFlag = 1;
	mMouseVec = new Vector2();
}
GameMgr::~GameMgr() {

}

void GameMgr::Initialize() {
	EffectMgr::Instance()->initialize();
	Image::Instance()->loadImage();
	Music::Instance()->loadMusic();
	pObjMgr = new ObjMgr(this);
	pBoard = new Board(*pObjMgr);
	pBackground = new Background;
	
	if (pBoard) {
		pBoard->Initialize();
	}
	if (pBackground) {
		pBackground->Initialize();
	}
	if (pObjMgr) {
		pObjMgr->Initialize();
	}
	Music::Instance()->enterBgm(4);
}

void GameMgr::Process() {
	
	pBoard->Process();
	pBackground->Process();

	pObjMgr->Process();
	Key_update();//Key�擾��ԍX�V

	printfDx("mStageCount:%d\n", mStageCount);
	if (mStageCountGoFlag) {//�X�e�[�W�J�E���g��i�߂�Ȃ�
		mStageCount++;//�i�߂�
	}
	
}

void GameMgr::Draw() {
	pBackground->Draw();
	pObjMgr->Draw();
	pBoard->Draw();
	
	if (pObjMgr->pPlayer->mLife < 0) {
		DrawRotaGraph((SCREEN_X_MAX - SCREEN_X_MIN) / 2, (SCREEN_Y_MAX - SCREEN_Y_MIN) / 2, 1.0, 0, Image::Instance()->getImage(3), true);

	}
	//�e�X�g�p�}�E�X�|�C���^�x�N�^�[�\��
	int x=static_cast<int>(mMouseVec->x);
	int y = static_cast<int>(mMouseVec->y);
	GetMousePoint(&x,&y);
	DrawFormatString(x + 10, y, GetColor(255, 255, 255), "(%d,%d)", x, y);


}

void GameMgr::Finalize() {
	delete pBoard;
	delete pBackground;
	delete pObjMgr;
	pBoard = 0;
	pBackground = 0;
	pObjMgr=0;

}

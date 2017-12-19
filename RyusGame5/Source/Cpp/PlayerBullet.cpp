#include "PlayerBullet.h"
#include "DxLib.h"
#include "Vector2.h"
PlayerBullet::PlayerBullet() {

	mY = 0;
	mX = 0;

	flag = false;
	Image=LoadGraph("Image/char_bullet01.png");

	mVec = new Vector2(0, 0);
	if (!mVec) {
		DxLib_End();
	}
}

void PlayerBullet::Initialize() {
	
}

void PlayerBullet::Enter_bullet() {
	flag = true;
	mX = 0;
	mY = 0;
}

void PlayerBullet::Process() {
	if ((ini_mX + mX) < -20 || 436 < (ini_mX + mX) || (ini_mY + mY) < -20 || 480 < (ini_mY + mY)) {
		flag = false;
	}
	if (flag == true) {
		mY = mY - 15;
	}
	//現在のベクターに代入
	mVec->x =ini_mX + mX;
	mVec->y =ini_mY + mY;
	
}

void PlayerBullet::Draw() {
	//自機キャラ弾の描画
	if (flag) {
		if ((ini_mX + mX) > -20 && 436 > (ini_mX + mX) && (ini_mY + mY) > -20 && 480 > (ini_mY + mY)) {
			DrawRotaGraph(ini_mX + mX, ini_mY + mY, 1.0, 0.0, Image, true);
		}
	}
}

void PlayerBullet::Finalize() {
}
#include "Player.h"
#include "DxLib.h"
#include "Key.h"
#include "Define.h"
#include "PlayerShot.h"
#include "PlayerBullet.h"
#include "Vector2.h"
#include "Bomb.h"
#include "Image.h"
#include "Music.h"
#include <vector>
using namespace std;
Player::Player() {
	LoadDivGraph("Image/char_tip.png",12,4,3,73,73,mImage);
	mMuki = 0;
	mTip_width = 4;
	mTip_x = 0;
	mFlag = true;
	mDeleteFlag = false;
	mMuteki_count = 0;
	mMuteki_flag = 0;

	mLife = 5;
	mDeathFlag = false;
	mVec = new Vector2((SCREEN_X_MAX-SCREEN_X_MIN)/2, (SCREEN_Y_MAX - SCREEN_Y_MIN) / 2);
	mDirection = new Vector2((SCREEN_X_MAX - SCREEN_X_MIN) / 2, (SCREEN_Y_MAX - SCREEN_Y_MIN) / 2);
	mvBomb = new vector<Bomb>;
}

Player::~Player() {
}

void Player::Initialize() {
	pPlayerShot = new PlayerShot;
}

void Player::Copy_PlayerBullet_xy(){
	int i;
	for (i = 0; i < 4; i++) {
		if (pPlayerShot->get_Bullet(i)->flag != true) {
			pPlayerShot->get_Bullet(i)->get_ini_mX() = mVec->x;
			pPlayerShot->get_Bullet(i)->get_ini_mY() = mVec->y;
		}
	}
}
double Player::getDirectionAngle() {
	Vector2 *tmp_Vec = new Vector2();
	tmp_Vec->x = mDirection->x - mVec->x;
	tmp_Vec->y = mDirection->y - mVec->y;
	return atan2(tmp_Vec->y, tmp_Vec->x);

}

double Player::getDistance() {
	double d;
	double tx = mDirection->x - mVec->x;
	double ty = mDirection->y - mVec->y;

	d = sqrt(tx*tx + ty*ty);
	return d;
}

void Player::Process() {
	Copy_PlayerBullet_xy();
	double dx=0, dy=0, tx=0, ty=0;
	mCount = mCount % 560;//560に意味はない。intがオーバーフローを起こさないようにするため。
	mTip_x = static_cast<int>(mCount / 8) % 4;
	mMuki = 0;
	if (!(mLife < 0)) {

		if (Key_get(KEY_INPUT_UP)>0) {
			dy -= C_MOVEMENT;
		}
		if (Key_get(KEY_INPUT_DOWN)>0) {
			dy += C_MOVEMENT;
		}
		if (Key_get(KEY_INPUT_RIGHT)>0) {
			dx += C_MOVEMENT;
			mMuki = 1;
		}
		if (Key_get(KEY_INPUT_LEFT)>0) {
			dx -= C_MOVEMENT;
			mMuki = 2;
			}
		
	}
	if (SCREEN_Y_MIN < mDirection->y + dy&&mDirection->y + dy < SCREEN_Y_MAX&& SCREEN_X_MIN< mDirection->x + dx&&mDirection->x + dx < SCREEN_X_MAX ) {
		mDirection->x += dx;
		mDirection->y += dy;
	}
	mCount++;

	double mDirectionAngle=getDirectionAngle();
	double mDistance = getDistance();
	double tc=cos(mDirectionAngle)*mDistance / 10.0;
	double ts=sin(mDirectionAngle)*mDistance / 10.0;
	if (SCREEN_Y_MIN < mVec->y+ts&&mVec->y+ts < SCREEN_Y_MAX  && SCREEN_X_MIN < mVec->x+tc&&mVec->x+tc < SCREEN_X_MAX) {
		mVec->x += tc;
		mVec->y += ts;
	}



	if (mMuteki_count == 0 && mMuteki_flag&&mDeathFlag) {
		mLife--;
		mMuteki_flag = true;
		mMuteki_count++;
		mDeathFlag = false;

	}else if (mMuteki_count<180&&mMuteki_flag) {
		mFlag = mCount % 2;//0か１
		mMuteki_flag = true;
		mMuteki_count++;
	}
	else {
		mMuteki_count = 0;
		mMuteki_flag = false;
		mFlag = true;
	}
	
	if (mLife < 0) {
		printfDx("game over\n");
		mFlag = false;

	}
	else {//生きてたら
		pPlayerShot->Process();
	}
	
}

void Player::Draw() {



	if (mFlag != false) {
		DrawRotaGraph(mVec->x, mVec->y, 1.0, 0.0, mImage[mMuki*mTip_width + mTip_x], true);
	}

		
		pPlayerShot->Draw();


}

void Player::Finalize(){
	delete pPlayerShot;
	pPlayerShot = 0;
}


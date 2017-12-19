#include "Zako.h"
#include "DxLib.h"
#include "ZakoActPattern.h"
#include "Vector2.h"
#include "ZakoShot.h"
#include "Player.h"
#include <vector>
using namespace std;


//ZakoActPatternとZakoは作り直し
Zako::Zako(const t_enemy_order&  order,const int* image,Vector2* vec) {

	mPlayerVec = vec;
	mMuki = 1;
	mTip_width = 3;
	mTip_x = 0;
	mCount = 0;
	mZako_in_count = 0;
	mCount_motion = 0;
	pZako_data = &order;
	mFlag = true;

	mImage = image;
	pZakoActPattern = 0;

	mVec = new Vector2(order.x,order.y);

	mvZakoShot = new vector<ZakoShot>;

	pZakoActPattern = new ZakoActPattern(*pZako_data,mVec);
	if (!pZakoActPattern) {
		printfDx("alocate error!");
		DxLib_End();
	}
}
Zako::~Zako(){
}

void Zako::Initialize() {
}

void Zako::enterShot() {

	if (pZako_data->bltime == mZako_in_count) {
		(*mvZakoShot).push_back(ZakoShot(mVec, *pZako_data,mPlayerVec));
		printfDx("enterShot\n");
	}
}
void Zako::calcShot() {
	int i;
	for (i = 0; i < (*mvZakoShot).size(); i++) {
		if ((*mvZakoShot)[i].mFlag) {
			(*mvZakoShot)[i].calcShot(&(*mvZakoShot)[i].mFlag,mFlag);

		}

	}
	for (i = 0; i < (*mvZakoShot).size(); i++) {
		if ((*mvZakoShot)[i].mFlag == 0) {
			pZakoShot = (*mvZakoShot).begin();
			pZakoShot += i;
			(*mvZakoShot).erase(pZakoShot);
		}
	}

}
void Zako::Process() {


	mCount_motion = mZako_in_count % 560;//560に意味はない。intがオーバーフローを起こさないようにするため。
	mTip_x = static_cast<int>(mCount_motion / 9) % 3;
	if (pZakoActPattern->mVx < -1) {
		mMuki = 0;
	}
	else if (pZakoActPattern->mVx > 1) {
		mMuki = 2;
	}
	else {
		mMuki = 1;
	}

	mCount++;
	if (mFlag != false) {//登録しているときだけカウントアップ
		mZako_in_count++;
		pZakoActPattern->mZako_count = &mZako_in_count;

		pZakoActPattern->Process();
	}

	if (!(0 < mVec->x&&mVec->y< 480 && 0 < mVec->y&&mVec->y < 480)) {
		mFlag = false;
	}

	enterShot();
	calcShot();

}
void Zako::Draw() {
	if (mFlag) {
		DrawRotaGraph(mVec->x,mVec->y, 1.0, 0.0, (mImage[mMuki*mTip_width + mTip_x]), true);
	}
	int i;
	for (i = 0; i < (*mvZakoShot).size(); i++) {
		(*mvZakoShot)[i].draw();
	}
	
}
void Zako::Finalize() {
}
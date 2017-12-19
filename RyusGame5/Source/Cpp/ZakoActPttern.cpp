#include "ZakoActPattern.h"
#include "math.h"
#include "Define.h"
#include "Vector2.h"
#include "DxLib.h"
ZakoActPattern::ZakoActPattern(const t_enemy_order& pZako_pattern,Vector2* vec) {
	pZako_data = &pZako_pattern;
	mAcc = 0;
	mAngle = 0;
	mSpd = 0;
	mVx = 0; mVy = 0;
	mZako_count = 0;
	mVec = vec;

}

ZakoActPattern::~ZakoActPattern() {
}

void ZakoActPattern::Process() {

	switch (pZako_data->pattern) {
	case 1:
		Zako_act_01();
		break;
	case 2:
		Zako_act_02();
		break;
	case 3:
		Zako_act_03();
		break;
	default:
		printfDx("Out of zako_pattern\n");
		break;
	}
	Act_process();
}

void ZakoActPattern::Zako_act_01() {
	if (*mZako_count < 60) {
		mAngle = PI_D4;
		mSpd = 4;
		mAcc = 0.5;
		mAngle = mAngle + (PI_D4) * D60*(*mZako_count);
	}
	if (60 <= *mZako_count&&*mZako_count < 120) {
		mAngle = PI_D2;
		mSpd = 4;
		mAcc = 0.5;
	}

	
}

void ZakoActPattern::Zako_act_02() {
	if (*mZako_count < 60) {
		mAngle = PI_D4;
		mSpd = 4;
		mAcc = 0.5;
		mAngle = mAngle + (PI_D4)* D60*(*mZako_count);
		mSpd = 4.0-D60*(*mZako_count);
	}
	if (60 <= *mZako_count&&*mZako_count < 120) {
		mAngle = PI_D2;
		mSpd = 4;
		mAcc = 0.5;
		mAngle = mAngle + (PI_D2)* D60*(*mZako_count-60);

	}


}
void ZakoActPattern::Zako_act_03() {
}


void ZakoActPattern::Act_process() {
	mVx = cos(mAngle)*mSpd;
	mVy = sin(mAngle)*mSpd;
	mVec->x = mVec->x +mVx;
	mVec->y = mVec->y +mVy;

}

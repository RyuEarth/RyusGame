#include "Boss00.h"
void Boss00::DrawCharactor() {
	if (mFlag) {
		DrawRotaGraph(mVec->x, mVec->y, 1.0, 0.0, (Image::Instance()->getKaranChip()[mMuki*mTip_width + mTip_x]), true);
	}
}
void Boss00::AnimationTips() {
	mCount_motion = mCount % 560;//560に意味はない。intがオーバーフローを起こさないようにするため。
	mTip_x = static_cast<int>(mCount_motion / 8) % 5;
}
void Boss00::ShotKnd() {

}
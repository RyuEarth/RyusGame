#ifndef INCLUDED_EFFECT_ENTER_H
#define INCLUDED_EFFECT_ENTER_H

#include "Vector2.h"
class EffectEnter {
public:
	EffectEnter(Vector2* vec,int knd,int start, int time,int num) {
		mVec = new Vector2();
		*mVec = *vec;
		mKnd = knd;
		mTime = time;
		mNum = num;
		mFlag = 1;
		mCount = 0;
		mStart = start;
	}
	int mKnd, mTime, mNum,mFlag,mCount,mStart;
	Vector2 *mVec;

};

#endif // !INCLUDED_EFFECT_ENTER_H


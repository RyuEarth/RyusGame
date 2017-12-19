#ifndef INCLUDED_EFFECT_H
#define INCLUDED_EFFECT_H

#include "EffectMgr.h"

class Effect{
public:
	Effect(Vector2*,int);
	~Effect(){}

	void Initialize();
	void Process();
	void Draw();
	void Finalize();

	Effect* Get_this() {
		return this;
	}

	bool mFlag;
	//種類、カウント、ブレンドパラメータ、ブレンド方式、画像番号
	int mKnd, mCount, mAlpha, mBlend, mImage;
	double mExRate, mAngle;
	Vector2 *mVec;

	
};

#endif
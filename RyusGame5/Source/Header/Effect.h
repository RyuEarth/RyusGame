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
	//��ށA�J�E���g�A�u�����h�p�����[�^�A�u�����h�����A�摜�ԍ�
	int mKnd, mCount, mAlpha, mBlend, mImage;
	double mExRate, mAngle;
	Vector2 *mVec;

	
};

#endif
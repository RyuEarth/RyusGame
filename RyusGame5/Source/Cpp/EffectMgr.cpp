#include "EffectMgr.h"
#include "Effect.h"
#include "Define.h"
#include "Vector2.h"
#include "Image.h"
#include "DxLib.h"
#include "EffectEnter.h"
#include <vector>
using namespace std;


void EffectMgr::initialize(){
	mvEffect = new vector<Effect>;
	pEffect = (*mvEffect).begin();

	mvEnter = new vector<EffectEnter>;
	pEnter = (*mvEnter).begin();
}

void EffectMgr::effRegister(Vector2* vec, int knd) {
	if (!(*mvEffect).back().mFlag) {
		switch (knd) {
		case EffectKnd::DELETE_EFF00:
			(*mvEffect).back().mKnd = knd;
			(*mvEffect).back().mFlag = true;
			(*mvEffect).back().mCount = 0;
			(*mvEffect).back().mAngle = 0;
			(*mvEffect).back().mExRate = 0.5;
			(*mvEffect).back().mBlend = DX_BLENDMODE_ADD;
			(*mvEffect).back().mImage = 0;

			break;
		case EffectKnd::DELETE_EFF01:
			(*mvEffect).back().mKnd = knd;
			(*mvEffect).back().mFlag = true;
			(*mvEffect).back().mCount = 0;
			(*mvEffect).back().mAngle = 0;
			(*mvEffect).back().mExRate = 1.0;
			(*mvEffect).back().mBlend = DX_BLENDMODE_ADD;
			(*mvEffect).back().mImage = 0;

			break;
		case EffectKnd::HADOU_EFF:
			(*mvEffect).back().mKnd = knd;
			(*mvEffect).back().mFlag = true;
			(*mvEffect).back().mCount = 0;
			(*mvEffect).back().mAngle = 0;
			(*mvEffect).back().mExRate = 0.5;
			(*mvEffect).back().mBlend = DX_BLENDMODE_ADD;
			(*mvEffect).back().mImage = 1;
			break;
		case EffectKnd::CHARA_EFF00:
			(*mvEffect).back().mKnd = knd;
			(*mvEffect).back().mFlag = true;
			(*mvEffect).back().mCount = 0;
			(*mvEffect).back().mAngle = 0;
			(*mvEffect).back().mExRate = 1.0;
			(*mvEffect).back().mBlend = DX_BLENDMODE_ALPHA;
			(*mvEffect).back().mAlpha = 0;
			(*mvEffect).back().mImage = 2;
			break;
		default:
			break;
		}
		(*mvEffect).back().mCount++;

	}

}
void EffectMgr::effEnter(Vector2* vec,int knd) {
		(*mvEffect).push_back(Effect(vec, knd));
		effRegister(vec, knd);
}

void EffectMgr::effEnter2(Vector2* vec, int knd,int start,int time, int num) {
	(*mvEnter).push_back(EffectEnter(vec, knd, start,time, num));
}
void EffectMgr::effEnterConductor() {
	int i;
	for (i = 0; i<(*mvEnter).size(); i++) {
		if ((*mvEnter)[i].mFlag) {
			if ((*mvEnter)[i].mTime == 0)(*mvEnter)[i].mTime = 1;//mTime�Ŋ��邩��
			if ((*mvEnter)[i].mStart <= (*mvEnter)[i].mCount) {//�J�n����
				if ((*mvEnter)[i].mCount % (*mvEnter)[i].mTime == 0) {//���J�E���g���Ƃ�
					effEnter((*mvEnter)[i].mVec, (*mvEnter)[i].mKnd);//�G�t�F�N�g��o�^
				}
				if ((*mvEnter)[i].mCount >(*mvEnter)[i].mTime*(*mvEnter)[i].mNum) {//�񐔕��o�^������
					(*mvEnter)[i].mFlag = 0;//�E��
					pEnter = (*mvEnter).begin();
					pEnter += i;
					(*mvEnter).erase(pEnter);

				}
			}

			
		}
	}
	for (i = 0; i < (*mvEnter).size(); i++) {
		(*mvEnter)[i].mCount++;
	}
}

void EffectMgr::effCalc() {
	int i;
	for (i = 0; i < (*mvEffect).size();i++) {
		if ((*mvEffect)[i].mFlag) {
			switch ((*mvEffect)[i].mKnd)
			{
			case EffectKnd::DELETE_EFF00:

				if((*mvEffect)[i].mCount<30){
					(*mvEffect)[i].mAngle = PI*D60*2* (*mvEffect)[i].mCount;
					(*mvEffect)[i].mExRate = (*mvEffect)[i].mExRate+0.005;
					(*mvEffect)[i].mAlpha = 255;					
				}
				else {
					(*mvEffect)[i].mFlag = false;
				}
				(*mvEffect)[i].mCount++;
				break;
			case EffectKnd::DELETE_EFF01:

				if ((*mvEffect)[i].mCount<60) {
					(*mvEffect)[i].mAngle = PI*D60 * 2 * (*mvEffect)[i].mCount;
					(*mvEffect)[i].mExRate = (*mvEffect)[i].mExRate*1.05;
					(*mvEffect)[i].mAlpha = 255;
				}
				else {
					(*mvEffect)[i].mFlag = false;
				}
				(*mvEffect)[i].mCount++;
				break;
			case EffectKnd::HADOU_EFF:
				if ((*mvEffect)[i].mCount<60) {
					(*mvEffect)[i].mExRate = (*mvEffect)[i].mExRate*1.08;
					(*mvEffect)[i].mAlpha = 255;
				}
				else {
					(*mvEffect)[i].mFlag = false;
				}
				(*mvEffect)[i].mCount++;
				break;
			case EffectKnd::CHARA_EFF00:
				if ((*mvEffect)[i].mCount<60) {
					(*mvEffect)[i].mVec->x += 1;
					(*mvEffect)[i].mExRate = (*mvEffect)[i].mExRate*1.0;
					(*mvEffect)[i].mAlpha += 255/30;
				}else if (60<=(*mvEffect)[i].mCount &&(*mvEffect)[i].mCount<120) {
					(*mvEffect)[i].mVec->x += 1;
					(*mvEffect)[i].mExRate = (*mvEffect)[i].mExRate*1.0;
					(*mvEffect)[i].mAlpha -=255/30;
				}
				else {
					(*mvEffect)[i].mFlag = false;
				}
				(*mvEffect)[i].mCount++;
				break;
			default:
				break;
			}
		}
	}

	for (i = 0; i < (*mvEffect).size(); i++) {
		pEffect = (*mvEffect).begin();//iterator��擪��
		if (!(*mvEffect)[i].mFlag) {//�t���O���������Ă�����
			pEffect = pEffect + i;
			(*mvEffect).erase(pEffect);//�폜
		}
	}
}

void EffectMgr::Draw() {
	
	int i;
	for (i = 0; i < (*mvEffect).size(); i++) {
		if ((*mvEffect)[i].mAlpha > 255)(*mvEffect)[i].mAlpha = 255;
		int num = (*mvEffect)[i].mImage;
		SetDrawBlendMode((*mvEffect)[i].mBlend,(*mvEffect)[i].mAlpha);
		DrawRotaGraph((*mvEffect)[i].mVec->x, (*mvEffect)[i].mVec->y,
			(*mvEffect)[i].mExRate, (*mvEffect)[i].mAngle, Image::Instance()->getImage(num),true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	
}

/*
------�ȉ��c�[--------
#include "EffectMgr.h"
#include "EffectCircle.h"
#include "EffectMagic.h"

EffectMgr* EffectMgr::Instance() {
	static EffectMgr Instance;
	return &Instance;
}

//pEffectCircle�Ȃǂ�new����
void EffectMgr::Initialize() {
	pEffectCircle = new EffectCircle;
	pEffectMagic = new EffectMagic;
	if (!(pEffectCircle&&pEffectMagic)) {
		DxLib_End();
	}

}

*/
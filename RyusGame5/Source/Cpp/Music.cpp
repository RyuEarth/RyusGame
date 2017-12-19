#include "Music.h"
#include "Define.h"
#include "DxLib.h"
#include <iostream>
using namespace std;
void Music::loadMusic() {
	memset(mSe, 0, sizeof(int) * SE_NUM);
	memset(mSeFlag, 0, sizeof(int)*SE_NUM);
	memset(mBgm, 0, sizeof(int)*BGM_NUM);
	memset(mBgmFlag, 0, sizeof(int)*BGM_NUM);

	mSe[0]=LoadSoundMem("Music/SE/enemy_shot.wav");
	mSe[1] = LoadSoundMem("Music/SE/death0.wav");
	mSe[2] = LoadSoundMem("Music/SE/effect_01.ogg");
	mSe[3] = LoadSoundMem("Music/SE/effect_02.ogg");
	mBgm[4] = LoadSoundMem("Music/BGM/stage02.ogg");
}

void Music::enterSe(int n) {
	mSeFlag[n] = 1;
}
void Music::enterBgm(int n) {
	mBgmFlag[n] = 1;
}

void Music::playMusic() {
	for (int i = 0; i < SE_NUM; i++) {
		if (mSeFlag[i] == 1) {
			PlaySoundMem(mSe[i],DX_PLAYTYPE_BACK);
		}
		mSeFlag[i]= 0;
	}

	for (int i = 0; i < BGM_NUM; i++) {
		if (mBgmFlag[i] == 1) {
			PlaySoundMem(mBgm[i], DX_PLAYTYPE_BACK);
		}
		mBgmFlag[i] = 0;
	}
}


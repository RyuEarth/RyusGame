#ifndef INCLUDED_MUSIC_H
#define INCLUDED_MUSIC_H

#include "Define.h"
class Music {
public:
	static Music* Instance() {
		static Music mInstance;
		return &mInstance;
	}
	int mSe[SE_NUM];
	int mSeFlag[SE_NUM];

	int mBgmFlag[BGM_NUM];
	int mBgm[BGM_NUM];
	void loadMusic();
	void enterSe(int n);
	void enterBgm(int n);

	void playMusic();
private:
	Music() {}
	~Music(){}
	Music& operator=(const Music& ){}
};

#endif

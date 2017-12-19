#include "Effect.h"
#include "Vector2.h"
Effect::Effect(Vector2* vec,int knd) {
	mVec = new Vector2;
	
	*mVec = *vec;
	mKnd = knd;

	mFlag = false;
	mExRate = 1.0;
	mCount = 0;
	mAngle = 0;
	mImage = 0;
	mAlpha = 255;
}


/*
//memo
//一度だけ実行
while(1){

	static int count=0;
	//実行内容
	if(count==0){
		hoge();
		count++;
	}
	
}
while(1){
	int count=1;
	if(count==1&&deadjudge()){//死ぬ瞬間ならば
		count=2;//死ぬ瞬間の状態
	}
	if(count==2){
		count=0;//死んだ状態に移行
	}

	
}
*/
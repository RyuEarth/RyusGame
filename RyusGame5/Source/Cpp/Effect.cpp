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
//��x�������s
while(1){

	static int count=0;
	//���s���e
	if(count==0){
		hoge();
		count++;
	}
	
}
while(1){
	int count=1;
	if(count==1&&deadjudge()){//���ʏu�ԂȂ��
		count=2;//���ʏu�Ԃ̏��
	}
	if(count==2){
		count=0;//���񂾏�ԂɈڍs
	}

	
}
*/
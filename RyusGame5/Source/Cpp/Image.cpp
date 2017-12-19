#include "Image.h"
#include "DxLib.h"
#include <vector>
using namespace std;

void Image::loadImage() {
	mvImage = new vector<int>;
	/*
	mvBulletImage = new vector<int>;
	mvBulletPointer = new vector<vector<int>>;
	*/

	//effect
	(*mvImage).push_back(LoadGraph("Image/effect01.png"));//0
	(*mvImage).push_back(LoadGraph("Image/effect02.png"));//1
	(*mvImage).push_back(LoadGraph("Image/natuki.png"));//2キャラ
	(*mvImage).push_back(LoadGraph("Image/game_over.png"));//3ゲームオーバー
	//Bullet
	LoadDivGraph("Image/bullet01.png", 5, 5, 1, 20, 20, mBulletImage[0]);//0
	LoadDivGraph("Image/bullet02.png", 5, 5, 1, 20, 20, mBulletImage[1]);//1
	//立ち絵
	mTachieImage[0] = LoadGraph("Image/karan.png");
	//BossChip_karan
	mKaranChipImage[0] = LoadGraph("Image/karan_anime/karan_anime_00000.png");
	mKaranChipImage[1] = LoadGraph("Image/karan_anime/karan_anime_00001.png");
	mKaranChipImage[2] = LoadGraph("Image/karan_anime/karan_anime_00002.png");
	mKaranChipImage[3] = LoadGraph("Image/karan_anime/karan_anime_00003.png");
	mKaranChipImage[4] = LoadGraph("Image/karan_anime/karan_anime_00004.png");
	//PlayerZankiChip
	mZankiChipImage[0] = LoadGraph("Image/zanki_anime/zanki_anime_00000.png");
	mZankiChipImage[1] = LoadGraph("Image/zanki_anime/zanki_anime_00001.png");
	mZankiChipImage[2] = LoadGraph("Image/zanki_anime/zanki_anime_00002.png");
	//BombChip
	mBombChipImage[0] = LoadGraph("Image/bomb_anime/bomb_anime_00000.png");
	mBombChipImage[1] = LoadGraph("Image/bomb_anime/bomb_anime_00001.png");
	mBombChipImage[2] = LoadGraph("Image/bomb_anime/bomb_anime_00002.png");

	/*
	mvBulletPointer->push_back(vector<int>(0));
	LoadDivGraph("Image/bullet01.png", 5, 5, 1, 20, 20, &mvBulletPointer->back().back());//0

	mvBulletPointer->push_back(vector<int>(0));
	LoadDivGraph("Image/bullet02.png", 5, 5, 1, 20, 20, &mvBulletPointer->back().back());//1
	*/

}

int Image::getImage(int num) {

	return (*mvImage)[num];
}
int Image::getTachie(int num) {
	return mTachieImage[num];
}
int* Image::getKaranChip() {
	return mKaranChipImage;
}
int* Image::getZankiChip() {
	return mZankiChipImage;
}
int* Image::getBombChip() {
	return mBombChipImage;
}
int* Image::getBulletImage(int num) {
	return mBulletImage[num];
}

#ifndef INCLUDED_IMAGE_H
#define INCLUDED_IMAGE_H

#include <vector>
//singleton class
class Image {
public:
	static Image* Instance() {
		static Image mInstance;
		return &mInstance;
	}


	void loadImage();
	int getImage(int);//要素を渡すとグラフィックハンドルを返す
	int* getBulletImage(int);//弾の種類
	int getTachie(int);
	int* getKaranChip();
	int* getZankiChip();
	int* getBombChip();
private:

	Image(){}
	~Image(){}
	int mBulletImage[10][10];
	int mTachieImage[6];
	int mKaranChipImage[5];
	int mZankiChipImage[3];
	int mBombChipImage[3];
	Image& operator=(const Image& n){}

	std::vector<int>  *mvImage;

};

#endif

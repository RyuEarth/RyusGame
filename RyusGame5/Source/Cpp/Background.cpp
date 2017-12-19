#include "Background.h"
#include "Define.h"
#include "DxLib.h"

Background::Background() {
	mImage[0] = LoadGraph("Image/back_screen1.png");
	mBackground_Y = 0;
	count = 0;
}

Background::~Background() {
}

void Background::Initialize() {
}

void Background::Process() {
	mBackground_Y++;
}

void Background::Draw() {
	SetDrawArea(32,16 , 416, 464);
	DrawGraph(32, mBackground_Y%700-700, mImage[0], true);
	DrawGraph(32, mBackground_Y%700, mImage[0], true);
	SetDrawArea(0, 0, 640, 480);
	}

void Background::Finalize() {
}


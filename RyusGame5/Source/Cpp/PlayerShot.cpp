#include "PlayerShot.h"
#include "PlayerBullet.h"
#include "Key.h"
#include "DxLib.h"
#include "Define.h"
#include "Music.h"

PlayerShot:: PlayerShot() {
	for (int i = 0; i<C_BULLET_NUM; i++) {
		pPlayerBullet[i] = new PlayerBullet;
	}
}
PlayerShot::~PlayerShot() {
}

void PlayerShot::Initialize() {
}

bool PlayerShot::Search_bullet(const int& i) {
	return pPlayerBullet[i]->flag;
}

int PlayerShot::Search_bullet() {
	int i;
	for (i = 0; i <C_BULLET_NUM; i++) {
		if (pPlayerBullet[i]->flag) {
			return i;
		}
	}
}

//ÉVÉáÉbÉgÇìoò^Ç∑ÇÈä÷êî
void PlayerShot::enter_shot(PlayerBullet* p,int& i) {
	pPlayerBullet[i]->Enter_bullet();

}

void PlayerShot::Process() {
	int i;
	if (Key_get(KEY_INPUT_Z) == 1) {//èuä‘ìIÇ…ÇyÇí@Ç¢ÇΩÇÁ
		
		for (i = 0; i < C_BULLET_NUM; i++) {
			if(Search_bullet(i)==false){//égÇÌÇÍÇƒÇ¢Ç»Ç¢íeÇ™Ç†Ç¡ÇΩÇÁ
				break;

			}
			
		}
		if (0 <= i&&i < C_BULLET_NUM) {
			enter_shot(pPlayerBullet[i], i);
		}
	}
	for (int j = 0; j < C_BULLET_NUM; j++) {

		pPlayerBullet[j]->Process();
	}
	
}
void PlayerShot::Draw() {
	int i;
	for (i = 0; i < C_BULLET_NUM; i++) {
		pPlayerBullet[i]->Draw();
	}
}
void PlayerShot::Finalize() {
	delete [] pPlayerBullet;
	for (int i = 0; i < C_BULLET_NUM; i++) {
		pPlayerBullet[i] = 0;
	}
}
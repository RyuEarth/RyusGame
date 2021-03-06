#ifndef INCLUDED_PLAYER_SHOT_H
#define INCLUDED_PLAYER_SHOT_H
#include "Define.h"
class PlayerBullet;

class PlayerShot{
public:
	PlayerShot();
	~PlayerShot();

	void Initialize();
	void Process();
	void Draw();
	void Finalize();

	PlayerBullet* get_Bullet(int i) { return pPlayerBullet[i]; }//bulletのthisポインタを返す

	bool Search_bullet(const int& i);
	int Search_bullet();//trueな弾のflagの番号を返す
private:
	PlayerBullet* pPlayerBullet[C_BULLET_NUM];

	
	void enter_shot(PlayerBullet*,int&);
};

#endif
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

	PlayerBullet* get_Bullet(int i) { return pPlayerBullet[i]; }//bullet��this�|�C���^��Ԃ�

	bool Search_bullet(const int& i);
	int Search_bullet();//true�Ȓe��flag�̔ԍ���Ԃ�
private:
	PlayerBullet* pPlayerBullet[C_BULLET_NUM];

	
	void enter_shot(PlayerBullet*,int&);
};

#endif
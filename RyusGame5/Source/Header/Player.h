#ifndef INCLUDE_PLAYER_H
#define INCLUDE_PLAYER_H

#include <vector>
using namespace std;
class PlayerShot;
class PlayerBullet;
class Vector2;
class Bomb;
class Player{

public:

	Player();
	~Player();
	void Initialize();
	void Process();
	void Draw();
	void Finalize();

	Vector2* Get_vector() {
		return mVec;
	}

	PlayerShot* pPlayerShot;
	bool mDeleteFlag;//死亡エフェクトフラグ
	bool mFlag;//描画フラグ
	int mMuteki_count;
	bool mMuteki_flag;
	Vector2* mVec;
	Vector2* mDirection;
	int mCount;
	bool mDeathFlag;
	int mLife;
private:

	vector<Bomb> *mvBomb;
	double mDirectionAngle;
	double mDistance;

	int mImage[12];
	
	int mMuki;
	int mTip_width;
	int mTip_x;

	
	void Copy_PlayerBullet_xy();
	double getDirectionAngle();
	double getDistance();
};

#endif

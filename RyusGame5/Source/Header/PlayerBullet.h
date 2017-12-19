#ifndef INCLUDED_PLAYER_BULLET_H
#define INCLUDED_PLAYER_BULLET_H


class Vector2;
class PlayerBullet{
public:
	PlayerBullet();
	~PlayerBullet() {}

	double& get_ini_mX() { return ini_mX; }
	double& get_ini_mY() { return ini_mY; }

	int flag;
	/*
	int mX, mY, mCount;
	//座標、カウント、ダメージ値
	double mSpd, mSpd_acc;
	//スピード、加速度
	*/
	void Enter_bullet();

	void Initialize();
	void Process();
	void Draw();
	void Finalize();

	Vector2* Get_vec() {
		return mVec;
	}
private:
	double mX, mY;
	double ini_mX, ini_mY;
	Vector2* mVec;
	int Image;
	
	

};

#endif

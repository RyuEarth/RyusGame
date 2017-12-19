#ifndef INCLUDED_BOSS_H
#define INCLUDED_BOSS_H

#include "Enemy.h"//Enemy.h��Struct��include�ς�
#include <vector>
using namespace std;

class BossShot;
class PlayerShot;
class BossActPattern;
class Vector2;
class Boss{
public:
	Boss(Vector2*, vector<Zako>*, int knd);//player�̃x�N�^�[,�G��
	~Boss();

	void Initialize();
	void Process();
	void Draw();
	void Finalize();

	const t_enemy_order* pZako_data;


	const int *mImage;
	double x, y, sp;
	//�`��t���O
	int mFlag;
	//�o�^���ړ��t���O
	int mEnterMoveFlag;
	//�V���b�g�J�n�t���O
	int mStartShotFlag;
	//���Ńt���O
	int mDeleteFlag;
	//�V���b�g�t���O
	int mShotFlag;
	//���
	int mKnd;
	//�ő�HP
	int mHp;
	vector<BossShot> *mvBossShot;
	vector<BossShot>::iterator pBossShot;
	vector<Zako> *mvZako;
	Vector2* Get_vector() {//���݂̃x�N�^�[��Ԃ�
		return mVec;
	}

private:
	/*
	�N���X����enum��錾���Ă�cpp���Ŏg���Ȃ�(switch�Ȃ�)
	enum ShotKnd {
		KND00,
		KND01,
		KND02,
		KND03
	};
	enum ShotCount{
		SHOT00=500,
		SHOT01=600,
		SHOT02=700,
		
	};
	*/
	void calcEnterMove();
	void createShot(int ShotKnd);
	void enterShot();
	void calcShot();

	BossActPattern* pBossActPattern;

	PlayerShot* pPlayerShot;

	Vector2* mPlayerVec;
	Vector2* mVec;

	int mCount_motion;
	int mMuki;
	int mActKnd;
	int mTip_width;
	int mTip_x;
	int mCount;
	int mEnterMoveCount;
	int mShotCount;
	int mShotKnd;
};
#endif
#ifndef INCLUDED_DEFINE_H
#define INCLUDED_DEFINE_H

#define SCREEN_X 640
#define SCREEN_X_MAX 416
#define SCREEN_X_MIN 32
#define SCREEN_X_HALF ((SCREEN_X_MAX-SCREEN_X_MIN)/2)

#define SCREEN_Y 480
#define SCREEN_Y_MAX 464
#define SCREEN_Y_MIN 16
#define SCREEN_Y_HALF ((SCREEN_Y_MAX-SCREEN_Y_MIN)/2)
#define C_MOVEMENT 4

#define C_ROUND 10.0		//�L�������a
#define C_BULLET_NUM 6		//�L�����V���b�g��
#define C_BULLET_ROUND 15.0//�L�����V���b�g���a
#define ZAKO_ROUND 10.0     //�G�����a
#define ZAKO_BULLET_ROUND 5.0//�G���V���b�g���a
#define BOSS_BULLET_ROUND 5.0//�{�X�V���b�g���a

#define ENEMY_ORDER 100 //�o�^�\�G��
#define SE_NUM	100		//SE�o�^�\��
#define BGM_NUM 100		//BGM�o�^�\��

#define PI 3.14159265
#define PI2 6.28318530
#define PI_D2 1.57079632
#define PI_D4 0.78539816


#define D60 0.016666666
//�{�X�����蔻��
enum BossRound {
	BOSSROUND00 = 20,
	BOSSROUND01 = 20,
};
//�摜���
enum ImageKnd {
	DELETE_EFF_IMAGE,

};
//�G�t�F�N�g�̎��
enum EffectKnd {
	DELETE_EFF00,
	DELETE_EFF01,
	HADOU_EFF,
	CHARA_EFF00,
};

enum BossEnterCnt {
	BOSS_CNT_00=200,
};
enum BossKnd {
	BOSS_KND_00,
};

#endif
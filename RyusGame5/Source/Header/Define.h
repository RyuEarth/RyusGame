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

#define C_ROUND 10.0		//キャラ半径
#define C_BULLET_NUM 6		//キャラショット数
#define C_BULLET_ROUND 15.0//キャラショット半径
#define ZAKO_ROUND 10.0     //雑魚半径
#define ZAKO_BULLET_ROUND 5.0//雑魚ショット半径
#define BOSS_BULLET_ROUND 5.0//ボスショット半径

#define ENEMY_ORDER 100 //登録可能敵数
#define SE_NUM	100		//SE登録可能数
#define BGM_NUM 100		//BGM登録可能数

#define PI 3.14159265
#define PI2 6.28318530
#define PI_D2 1.57079632
#define PI_D4 0.78539816


#define D60 0.016666666
//ボスあたり判定
enum BossRound {
	BOSSROUND00 = 20,
	BOSSROUND01 = 20,
};
//画像種類
enum ImageKnd {
	DELETE_EFF_IMAGE,

};
//エフェクトの種類
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
#ifndef INCLUDED_ZAKO_ACT_PATTERN
#define INCLUDED_ZAKO_ACT_PATTERN

#include "Struct.h"
class Vector2;
class ZakoActPattern {
public:
	ZakoActPattern(const t_enemy_order& pZako_pattern,Vector2* vec);
	~ZakoActPattern();

	void Process();
	void Act_process();
	void Zako_act_01();
	void Zako_act_02();
	void Zako_act_03();

	Vector2* mVec;
	int* mZako_count;
	double mVx, mVy;//ｘ方向ｙ方向に対する速度
private:
	const t_enemy_order* pZako_data;

	
	double mAcc;//加速度
	double mAngle;//角度
	double mSpd;//速度
	
	
};

#endif

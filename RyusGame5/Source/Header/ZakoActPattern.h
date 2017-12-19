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
	double mVx, mVy;//�������������ɑ΂��鑬�x
private:
	const t_enemy_order* pZako_data;

	
	double mAcc;//�����x
	double mAngle;//�p�x
	double mSpd;//���x
	
	
};

#endif

#ifndef INCLUDED_BOSS_ACT_PATTERN_H
#define INCLUDED_BOSS_ACT_PATTERN_H

class Vector2;
class Boss;
class BossActPattern {
public:
	BossActPattern(Boss* boss);
	~BossActPattern();

	void  process();
	void act01();
	
private:
	int mKnd;
	double mAcc;//加速度
	double mAngle;//角度
	double mSpd;//速度
	Boss *pBoss;
};


#endif
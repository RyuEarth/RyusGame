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
	double mAcc;//�����x
	double mAngle;//�p�x
	double mSpd;//���x
	Boss *pBoss;
};


#endif
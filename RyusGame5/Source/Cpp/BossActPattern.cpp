#include "BossActPattern.h"
#include "Boss.h"
#include "Vector2.h"


BossActPattern::BossActPattern(Boss* boss) {
	pBoss=boss;//actpatternベクターとbossベクターは連動
}

BossActPattern::~BossActPattern() {

}

void BossActPattern::process() {
	//ショットパターンによって行動パターンが異なる
	switch (pBoss->mKnd) {
	case 0:
		act01();
		break;
	case 1:
		break;
	default:
		break;
	}
	
}

void BossActPattern::act01() {

}





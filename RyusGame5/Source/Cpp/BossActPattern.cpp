#include "BossActPattern.h"
#include "Boss.h"
#include "Vector2.h"


BossActPattern::BossActPattern(Boss* boss) {
	pBoss=boss;//actpattern�x�N�^�[��boss�x�N�^�[�͘A��
}

BossActPattern::~BossActPattern() {

}

void BossActPattern::process() {
	//�V���b�g�p�^�[���ɂ���čs���p�^�[�����قȂ�
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





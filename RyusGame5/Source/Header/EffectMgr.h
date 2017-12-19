#ifndef INCLUDED_EFFECT_MGR
#define INCLUDED_EFFECT_MGR

#include <vector>
using namespace std;
//singleton

class Vector2;
class Effect;
class EffectEnter;
class EffectMgr {
public:

	static EffectMgr* Instance() {
		static EffectMgr mInstance;
		return &mInstance;
	}
	
	void initialize();
	void effCalc();
	void effEnter(Vector2* ,int);
	void effEnter2(Vector2*, int knd,int start, int time, int num);
	void effRegister(Vector2*,int);//�G�t�F�N�g�̎�ނ��Ƃɓo�^�̎d�����Ⴄ
	void effEnterConductor();
	void Draw();
private:

	//vector�e���v���[�g�N���X���g�����G�t�F�N�g�Ǘ�
	vector<Effect> *mvEffect;
	vector<Effect>::iterator pEffect;
	
	vector<EffectEnter> *mvEnter;
	vector<EffectEnter>::iterator pEnter;
	EffectMgr() {}
	~EffectMgr() {}
	EffectMgr(const EffectMgr& n) {}
	EffectMgr& operator=(const EffectMgr& n) {}


};


#endif
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
	void effRegister(Vector2*,int);//エフェクトの種類ごとに登録の仕方が違う
	void effEnterConductor();
	void Draw();
private:

	//vectorテンプレートクラスを使ったエフェクト管理
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
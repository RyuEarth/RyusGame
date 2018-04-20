// ConsoleTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "ConsoleTest.h"
#include "Windows.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class DelegateBase {
public:
	DelegateBase() {};
	virtual ~DelegateBase() {};
	virtual void operator()(int value1, int value2) = 0;	// 関数プロトタイプ「void xxx(int,int);」
};

template < class T >
class Delegate : public DelegateBase {
public:
	Delegate() {};
	virtual ~Delegate() {};

	// オペレータ実装
	virtual void operator()(int value1, int value2) {		// 関数プロトタイプ「void xxx(int,int);」
		(m_obj->*m_func)(value1, value2);		// ハンドラ実行：関数プロトタイプ「void xxx(int,int);」
	}

	typedef void (T::*EventFunc)(int, int);		// 関数プロトタイプ「void xxx(int,int);」

												// オブジェクトとメソッドを登録
	void set(T* obj, EventFunc func) {
		m_obj = obj;
		m_func = func;
	}

	// デリゲータ生成関数
	static DelegateBase* createDelegator(T* obj, EventFunc func) {
		Delegate* dg = new Delegate;
		dg->set(obj, func);
		return dg;
	}
protected:
	T* m_obj;               // オブジェクト
	EventFunc m_func;       // 関数ポインタ
};

class CHoge01 {
public:
	void func01(int a, int b) {		// 関数プロトタイプ「void xxx(int,int);」
		cout << "func01=" << a + b << endl;
	}
};

class CPiyo02 {
public:
	void funcABC(int q1, int q2) {	// 関数プロトタイプ「void xxx(int,int);」
		cout << "funcABC=" << q1 - q2 << endl;
	}
	void funcXYZ(int q1, int q2) {	// 関数プロトタイプ「void xxx(int,int);」
		cout << "funcXYZ=" << q1 * q2 << endl;
	}
};
void FlameCount() {
	flameCount++;
}

void FlameDisplay() {
	cout << "FlameCount:" << flameCount << endl;
}

void FlameProcess() {
	FlameDisplay();
	FlameCount();
	Sleep(SEC_PER_FLAME * 1000);
}

void MainLoop() {


	int flag = 1;
	int count = 0;
	while (flag) {
		FlameProcess();
		//以下に処理を書いていく

	}
}

void OneFlame() {

	//以下に処理を書いていく
	CHoge01 obj_hoge;
	CPiyo02 obj_piyo;

	//デリゲータに包む
	DelegateBase *func01_DG = Delegate<CHoge01>::createDelegator(&obj_hoge, (&CHoge01::func01));
	DelegateBase *funcABC_DG = Delegate<CPiyo02>::createDelegator(&obj_piyo, &CPiyo02::funcABC);
	DelegateBase *funcXYZ_DG = Delegate<CPiyo02>::createDelegator(&obj_piyo, &CPiyo02::funcXYZ);
	
	list<DelegateBase*> lim;
	lim.push_back(func01_DG);
	lim.push_back(funcABC_DG);
	lim.push_back(funcXYZ_DG);

	list<DelegateBase*>::iterator ite = lim.begin();
	while (ite != lim.end()) {
		DelegateBase *ptr = (*ite);
		(*ptr)(10, 8);
		ite++;
	}
	system("pause");
	return;
}
int main()
{
	OneFlame();
	return 0;
}


// ConsoleTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "ConsoleTest.h"
#include "Windows.h"
#include <iostream>
#include <string>
#include <boost\signals2\signal.hpp>
#include <boost/optional/optional_io.hpp>
using namespace std;


class A {
public:
	string MethodA(int arg1, float arg2) {
		cout << "A::MethodA(" << arg1 << "," << arg2 << ") is called" << endl;
		return "value is A.";
	}
};

class B {
public:
	string MethodB(int arg1, float arg2) {
		cout << "B::MethodB(" << arg1 << "," << arg2 << ") is called" << endl;
		return "value is B.";
	}
};

class C {
public:
	string MethodC(int arg1, float arg2) {
		cout << "C::MethodC(" << arg1 << "," << arg2 << ") is called" << endl;
		return "value is C.";
	}
};
class ShotAbs {
public:
	virtual void ShotInterface() = 0;
	
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
	boost::signals2::signal<string(int, float)> signal;

	A objA;
	B objB;
	C objC;

	signal.connect(boost::bind(&A::MethodA, &objA, _1, _2));
	signal.connect(boost::bind(&B::MethodB, &objB, _1, _2));
	signal.connect(boost::bind(&C::MethodC, &objC, _1, _2));
	signal.connect(boost::bind(&B::MethodB, &objB, _1, _2));
	signal.connect(boost::bind(&A::MethodA, &objA, _1, _2));
	cout << *signal(123, 45.6) << endl;

	cout << "--------" << endl;

	signal.disconnect(boost::bind(&B::MethodB, &objB, _1, _2));
	signal.connect(boost::bind(&C::MethodC, &objC, _1, _2));
	cout << *signal(456, 7.89) << endl;

	system("pause");
	return;
}
int main()
{
	OneFlame();
	return 0;
}


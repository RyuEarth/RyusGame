// ConsoleTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "ConsoleTest.h"
#include "Windows.h"
#include <iostream>
using namespace std;

void CausingEvent1();
void CausingEvent2();
void ConcreteFunction();

void TestFunction1(int i,int j) {
	cout << "function pointer1" << endl;
	cout << "i:" << i << "\t" << "j:" << j << endl;
	functionNum = 1;
}
void TestFunction2(int i, int j) {
	cout << "function pointer2" << endl;
	cout << "i:" << i << "\t" << "j:" << j << endl;
	functionNum = 2;
}
void TestFunction3(int i, int j) {
	cout << "function pointer3" << endl;
	cout << "i:" << i << "\t" << "j:" << j << endl;
	functionNum = 0;
}


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
	void(*po[])(int, int) = {
		TestFunction1,
		TestFunction2,
		TestFunction3
	};
	int flag = 1;
	int count = 0;
	while (flag) {
		FlameProcess();
		//以下に処理を書いていく
		if (count < 100) {
			(*po[functionNum])(functionNum, flag);
		}
		else {
			eventFlag = 1;//任意のフラグ
		}
		
		count++;

		CausingEvent1();
	}
}

void CausingEvent1() {
	if (Flag1 == 0 && eventFlag == 1) {
		Flag1 = 1;
	}
	if (Flag1 == 1) {
		CausingEvent2();
	}
	if (Flag1 == 2) {
		system("pause");
		return;
	}
}

static int time = 0;
static int tu = 50;
void CausingEvent2() {
	if (Flag2 == 0) {
		Flag2 = 1;
	}
	if (Flag2 == 1) {
		time++;
		if (time < tu) {
			ConcreteFunction();
			return;
		}
		else {
			Flag2 = 2;
		}
	}
	if (Flag2 == 2) {
		Flag1 = 2;
	}
}

void ConcreteFunction() {
	cout << "ConcreteFunction" << endl;
}
void OneFlame() {
	//以下に処理を書いていく

	return;
}
int main()
{
	MainLoop();
	return 0;
}


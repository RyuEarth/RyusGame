// ConsoleTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "ConsoleTest.h"
#include "Windows.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

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
	system("pause");
	return;
}
int main()
{
	OneFlame();
	return 0;
}


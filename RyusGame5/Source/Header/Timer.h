#ifndef INCLUDED_TIMER_H
#define INCLUDED_TIMER_H

class Timer {
public:
	Timer();
	~Timer();
	int elapsedFlame;//�o�ߎ��ԁi�t���[���P�ʁj
	double elapsedSecond;//�o�ߎ��ԁi�b�P�ʁj
	void Stop();
	void Go();
	void Reset();
private:
	void CountSecond();
	void CountFlame();
};
#endif
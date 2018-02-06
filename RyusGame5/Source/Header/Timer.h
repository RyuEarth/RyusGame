#ifndef INCLUDED_TIMER_H
#define INCLUDED_TIMER_H

class Timer {
public:
	Timer();
	~Timer();
	int elapsedFlame;//経過時間（フレーム単位）
	double elapsedSecond;//経過時間（秒単位）
	void Stop();
	void Go();
	void Reset();
private:
	void CountSecond();
	void CountFlame();
};
#endif
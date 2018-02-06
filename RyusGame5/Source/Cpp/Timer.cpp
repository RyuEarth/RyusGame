#include "Timer.h"

Timer::Timer() {
	elapsedFlame = 0;
	elapsedSecond = 0;
}

Timer::~Timer() {
}

void Timer::CountFlame() {
	if (timerState==TimerState.GO) {
		elapsedFlame++;
	}
}

void Timer::CountSecond() {
	elapsedSecond=(double)elapsedFlame / FLAME_RATE;
}

void Timer::Stop() {
	timerState=TimerState
}

void Timer::Go() {

}

void Timer::Reset() {

}
#include "FlashFunc.h"
#include "Timer.h"
FlashFunc::FlashFunc() {
	timer = new Timer();
}
FlashFunc::~FlashFunc() {

}
void FlashFunc::One() {
	if (timer->elapsedFlame == 1) {

	}
}
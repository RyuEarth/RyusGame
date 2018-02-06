#ifndef INCLUDED_FLASH_FUNC_H
#define INCLUDED_FLASH_FUNC_H
class Timer;
class FlashFunc {
public:
	FlashFunc() {
		timer = new Timer();
	}
	~FlashFunc();
	void One() {
		
	}
private:
	Timer* timer;
};

#endif

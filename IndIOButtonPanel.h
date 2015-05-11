#ifndef IndIOButtonPanel_h
#define IndIOButtonPanel_h

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

const int ENTER_PRESSED = 1;
const int UP_PRESSED = 2;
const int DOWN_PRESSED = 3;
const int NONE_PRESSED = 0;

class IndIOButtonPanel{
	public: 
		IndIOButtonPanel();
		IndIOButtonPanel(int pin);
		int readButtonPanel();
	private:
		int _pin;
};
#endif
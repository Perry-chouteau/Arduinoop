#ifndef Joystick_hpp
#define Joystick_hpp

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>

class Joystick {
  public:
  	Joystick(uint8_t pinX, uint8_t pinY, uint8_t pinSW) {
			_pinX = pinX;
			_pinY = pinY;
			_pinSW = pinSW;
			pinMode(pinX, INPUT);
			pinMode(pinY, INPUT);
			pinMode(pinSW, INPUT_PULLUP);
		};

  	int ReadX(){
			return analogRead(_pinX);
		};

  	int ReadY(){
			return analogRead(_pinY);
		};

  	bool ReadSW() {
      return digitalRead(_pinSW) ? true: false;
		};

  private:
  	uint8_t _pinX;
  	uint8_t _pinY;
  	uint8_t _pinSW;
};

#endif
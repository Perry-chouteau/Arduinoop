#ifndef Led_hpp
#define Led_hpp

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>

class Led {
  public:
  	Led(uint8_t pin) {
			_pin = pin;
			pinMode(_pin, OUTPUT);
		};

  	void DigitalWrite(uint8_t val){
			digitalWrite(_pin, val);
		};

  	void AnalogWrite(int val) {
			analogWrite(_pin, val);
		};

  private:
  	uint8_t _pin;
};

#endif /* Led */
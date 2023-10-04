#ifndef Potentiometer_hpp
#define Potentiometer_hpp

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>

class Potentiometer {
  public:
  	Potentiometer(uint8_t pin) {
			_pin = pin;
			pinMode(_pin, INPUT);
		};

  	int Read(){
			return analogRead(_pin);
		};

  private:
  	uint8_t _pin;
};

#endif /* Potentiometer */
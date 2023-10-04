#ifndef Button_hpp
#define Button_hpp

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>

class Button {
  public:
  	Button(uint8_t pin) {
			_pin = pin;
			pinMode(_pin, INPUT);
		};

  	bool Read(){
			return digitalRead(_pin) ? true: false;
		};

  private:
  	uint8_t _pin;
};

#endif /* Button */
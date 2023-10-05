#ifndef Led_hpp
#define Led_hpp

#include "IComponent.hpp"

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>

namespace Component {

	class Led: public IComponent {
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
	
			void Info() override {
        Serial.print("LED: ");
        Serial.println(_pin);
      }

	  private:
	  	uint8_t _pin;
	};

} // namespace Component

#endif /* Led */
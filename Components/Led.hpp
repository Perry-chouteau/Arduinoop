#ifndef Led_hpp
#define Led_hpp

#include "IComponent.hpp"

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>
#include "Arduino.h"

namespace Component {

	class Led: public IComponent {
	  public:
			Led() = default;

	  	Led(uint8_t pin) {
				_pin = pin;
				pinMode(pin, OUTPUT);
			};

			void On() {
				digitalWrite(_pin, HIGH);
			}

			void Off() {
				digitalWrite(_pin, LOW);
			}

	  	void AnalogWrite(int val) {
				analogWrite(_pin, val);
			};
	
			void Info() override {
        Serial.print("LED: ");
        Serial.println(_pin);
				Serial.flush();
      }

			void SetPin(uint8_t pin) {
				_pin = pin;
			}

	  private:
	  	uint8_t _pin;
			char str[4];
	};

} // namespace Component

#endif /* Led */
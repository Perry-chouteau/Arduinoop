#ifndef Potentiometer_hpp
#define Potentiometer_hpp

#include "IComponent.hpp"

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>

namespace Component
{

	class Potentiometer: public IComponent {
		public:
			Potentiometer(uint8_t pin) {
				_pin = pin;
				pinMode(_pin, INPUT);
			};

			int Read(){
				return analogRead(_pin);
			};

			void Info() override {
        Serial.print("Potentiometer: ");
        Serial.print(_pin);
      }

		private:
			uint8_t _pin;
	};
	
} // namespace Component

#endif /* Potentiometer */
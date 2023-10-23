#ifndef Button_hpp
#define Button_hpp

#include "IComponent.hpp"

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>

namespace Component {

	class Button: public IComponent {
		public:
			Button(uint8_t pin) {
				_pin = pin;
				pinMode(_pin, INPUT);
			};

			bool Read(){
				return digitalRead(_pin) ? true: false;
			};

      void Info() override {
        Serial.print("BUTTON : ");
        Serial.println(_pin);
      }


		private:
			uint8_t _pin;
	};

} //namespace Component

#endif /* Button */
#ifndef Button_hpp
#define Button_hpp

#include "IComponent.hpp"

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>

namespace Component {

	class Bluetooth: public IComponent {
		public:
			Bluetooth(uint8_t pin) {
				_pin = pin;
				pinMode(_pin, INPUT);
			};

//			bool Read(){
//			};

      void Info() override {
        Serial.print("BUTTON : ");
        Serial.println(_pin);
      }


		private:
			uint8_t _pin;
	};

} //namespace Component

#endif /* Button */
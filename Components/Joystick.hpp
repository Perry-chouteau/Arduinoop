#ifndef Joystick_hpp
#define Joystick_hpp

#include "IComponent.hpp"

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>
namespace Component {

	class Joystick: public IComponent {
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

			void Info() override {
        Serial.print("JOYSTICK: ");
        Serial.print("vrx=");
        Serial.print(_pinX);
        Serial.print(", vry=");
        Serial.print(_pinY);
        Serial.print(", sw=");
        Serial.println(_pinSW);
      }

		private:
			uint8_t _pinX;
			uint8_t _pinY;
			uint8_t _pinSW;
	};

} //namespace Component

#endif /* Joystick */
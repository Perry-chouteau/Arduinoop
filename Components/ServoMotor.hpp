#ifndef ServoMotor_hpp
#define ServoMotor_hpp

#include "IComponent.hpp"

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>
#include <Servo.h>

namespace Component {

	class ServoMotor: public IComponent {
		public:
			ServoMotor(uint8_t pin) {
				_pin = pin;
			}

			void Attach() {
				servo.attach(_pin);
			}

			void Write(int angle){
				servo.write(angle);
			};

      void Info() override {
        Serial.print("SERVOMOTOR : ");
        Serial.println(_pin);
      }

		private:
      Servo servo; // création de l'objet "servo"
			uint8_t _pin;
      
	};

} //namespace Component

#endif /* ServoMotor */
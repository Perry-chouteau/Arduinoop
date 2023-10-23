#ifndef WaterSensor_h
#define WaterSensor_h

#include "IComponent.hpp"
#include "Arduino.h"

namespace Component {

	class WaterSensor: public IComponent {
	  public:
	  	WaterSensor(uint8_t pin) {
				pinMode(_pin, INPUT);
			};

	  	int Read(){
				return analogRead(_pin);
			};


			void Info() override {
        Serial.print("WaterSensor: ");
        Serial.print(_pin);
      }

	  private:
	  	uint8_t _pin;
	};

}

#endif /* WaterSensor_h */
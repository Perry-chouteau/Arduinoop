#ifndef ArduinoNano_hpp
#define ArduinoNano_hpp

#include "IController.hpp"

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>
#include <Vector.h>

namespace Arduino {

	class Nano: public IController {
	  public:
	  	Nano() {};

	  private:
	  	uint8_t _pin;
	};
}

#endif /* ArduinoNano */
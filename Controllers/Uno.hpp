#ifndef Uno_hpp
#define Uno_hpp

#include "IController.hpp"

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>
#include <Vector.h>

namespace Arduino {

	class Uno: public IController {
	  public:
	  	Uno() {
			};

			Component::Led AddLed(uint8_t pin) override {
				return Component::Led(pin);
			};

			Component::LedRGB AddLedRGB(uint8_t pinR, uint8_t pinG, uint8_t pinB) override {
				return Component::LedRGB(pinR, pinG, pinB);
			};

			Component::Potentiometer AddPotentiometer(uint8_t pin) override {
				return Component::Potentiometer(pin);
			};

			Component::Dht11 AddDht11(uint8_t pin) override {
				return Component::Dht11(pin);
			};

			Component::Joystick AddJoystick(uint8_t pinX, uint8_t pinY, uint8_t pinSW) override {
				return Component::Joystick(pinX, pinY, pinSW);
			};

			Component::RfidRc522 AddRfidRc522() override {

			};

			Component::WaterSensor AddWaterSensor() override {

			};

	  private:
			Vector<IComponent> _components();
			Vector<uint8_t> _pinUsed();
	};

}
#endif /* Uno */
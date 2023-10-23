#ifndef Uno_hpp
#define Uno_hpp

#include "IController.hpp"

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>
#include <Vector.h>
#include <Array.h>

namespace Arduino {

	template <size_t T>
	class Uno: public IController {
	  public:
	  	Uno() {
			};
	  	~Uno() {
				for (int i = 0; i < _components.size(); i++) {
					delete _components[i];
				}
			};

			Component::Button& AddButton(uint8_t pin) override {
				Component::Button* button = new Component::Button(pin);
				_components.push_back(button);
				return *button;
			};

			Component::Led& AddLed(uint8_t pin) override {
				Component::Led* led = new Component::Led(pin);
				_components.push_back(led);
				return *led;
			};
			
			Component::LedRGB& AddLedRGB(uint8_t pinR, uint8_t pinG, uint8_t pinB) override {
				Component::LedRGB* ledrgb = new Component::LedRGB(pinR, pinG, pinB);
				_components.push_back(ledrgb);
				return *ledrgb;
			};

			Component::ServoMotor& AddServoMotor(uint8_t pin) override {
				Component::ServoMotor* servomotor = new Component::ServoMotor(pin);
				_components.push_back(servomotor);
				return *servomotor;
			};

			Component::Potentiometer& AddPotentiometer(uint8_t pin) override {
				Component::Potentiometer* potentiometer = new Component::Potentiometer(pin);
				_components.push_back(potentiometer);
				return *potentiometer;
			};

			Component::Dht11& AddDht11(uint8_t pin) override {
				Component::Dht11* dht11 = new Component::Dht11(pin);
				_components.push_back(dht11);
				return *dht11;
			};

			Component::Joystick& AddJoystick(uint8_t pinX, uint8_t pinY, uint8_t pinSW) override {
				Component::Joystick* joystick = new Component::Joystick(pinX, pinY, pinSW);
				_components.push_back(joystick);

				return *joystick;
			};

			Component::RfidRc522& AddRfidRc522() override {
				Component::RfidRc522* rfidRc522 = new Component::RfidRc522(0, 2, 3, 4, 5, 5, 6, 7);
				_components.push_back(rfidRc522);

				return *rfidRc522;
			};

			Component::WaterSensor& AddWaterSensor(uint8_t pin) override {
				Component::WaterSensor* watersensor = new Component::WaterSensor(pin);
				_components.push_back(watersensor);

				return *watersensor;
			};

			Component::Max72XX& AddMax72XX(int dataPin, int clkPin, int csPin, int numDevices = 1) override {
				Component::Max72XX* max72xx = new Component::Max72XX(dataPin, clkPin, csPin, numDevices);
				_components.push_back(max72xx);

				return *max72xx;
			};

			void List() {
				Serial.print("List: size=");
				Serial.println(_components.size());
				Serial.println("--------------");
				for (int i = 0; i < _components.size(); i++) {
					_components[i]->Info();
				}
				Serial.println("--------------");
			}

			int Size() {
				return _components.size();
			}

	  private:
			Array<IComponent*, T> _components;
//			Vector<uint8_t> _pinUsed;
	};
}

#endif /* Uno */
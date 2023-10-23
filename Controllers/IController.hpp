#ifndef IController_hpp
#define IController_hpp

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>
#include <Vector.h>

#include "../Components/Components.hpp"

//template<size_t T>
class IController {
  public:
  	virtual ~IController() = default;
    virtual Component::Button& AddButton(uint8_t pin) = 0;
    virtual Component::Led& AddLed(uint8_t pin) = 0;
    virtual Component::LedRGB& AddLedRGB(uint8_t pinR, uint8_t pinG, uint8_t pinB) = 0;
    virtual Component::ServoMotor& AddServoMotor(uint8_t pin);
    virtual Component::Potentiometer& AddPotentiometer(uint8_t pin) = 0;
    virtual Component::Dht11& AddDht11(uint8_t pin) = 0;
    virtual Component::Joystick& AddJoystick(uint8_t pinX, uint8_t pinY, uint8_t pinSW) = 0;
    virtual Component::RfidRc522& AddRfidRc522() = 0;
    virtual Component::WaterSensor& AddWaterSensor(uint8_t pin) = 0;
		virtual	Component::Max72XX& AddMax72XX(int dataPin, int clkPin, int csPin, int numDevices = 1) = 0;
    virtual void List() = 0;
};

#endif /* IController */
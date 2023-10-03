#ifndef LedRGB_hpp
#define LedRGB_hpp

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>

class LedRGB {
  public:
  	LedRGB(uint8_t pinR, uint8_t pinG, uint8_t pinB) {
			_pinR = pinR;
			_pinG = pinG;
			_pinB = pinB;
			pinMode(_pinR, OUTPUT);
			pinMode(_pinG, OUTPUT);
			pinMode(_pinB, OUTPUT);
		};

		//Digital
  	void DigitalWriteR(uint8_t val){
			digitalWrite(_pinR, val);
		};

  	void DigitalWriteG(uint8_t val){
			digitalWrite(_pinG, val);
		};

  	void DigitalWriteB(uint8_t val){
			digitalWrite(_pinB, val);
		};

  	void DigitalWriteRGB(uint8_t vR,uint8_t vG, uint8_t vB){
			  DigitalWriteR(vR);
			  DigitalWriteG(vG);
			  DigitalWriteB(vB);
		};
		
		//Analog
  	void AnalogWriteR(int val) {
			analogWrite(_pinR, val);
		};

  	void AnalogWriteG(int val) {
			analogWrite(_pinG, val);
		};

  	void AnalogWriteB(int val) {
			analogWrite(_pinB, val);
		};
  	void AnalogWriteRGB(int vR, int vG, int vB) {
			AnalogWriteR(vR);
			AnalogWriteG(vG);
			AnalogWriteB(vB);
		};

  private:
  	uint8_t _pinR;
  	uint8_t _pinG;
  	uint8_t _pinB;
};

#endif
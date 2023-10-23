#ifndef Max72XX_hpp
#define Max72XX_hpp

#include "IComponent.hpp"

#include "LedControl.h"
#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>
#include <Servo.h>

#define	OFF false
#define	ON true

namespace Component {

	class Max72XX: public IComponent {
		public:
			Max72XX(int dataPin, int clkPin, int csPin, int numDevices = 1): _lc(12,11,10,1) {
				_dataPin = dataPin;
				_clkPin = clkPin;
				_csPin = csPin;
				_numDevices = numDevices;
			}

			void Init() {
				for(int index=0;index<_lc.getDeviceCount();index++) {
    	    _lc.shutdown(index,false); 
			    _lc.setIntensity(index, 8);

		    }
			}

			template<bool state>
			void Turn(int addr, int row, int column) {
				_lc.setLed(addr, row, column, state);
			}

			void TurnRow(int addr, int row, byte value) {
				_lc.setRow(addr, row, value);
			}
			void TurnColumn(int addr, int column, byte value) {
				_lc.setColumn(addr, column, value);
			}

			template<int A>
			void ClearDisplay() {
					_lc.clearDisplay(A);
			}

		  int GetDeviceCount() {
				return _lc.getDeviceCount();
			}

      void Info() override {
        Serial.print("MAX72XX : ");
        Serial.println(_dataPin);
        Serial.println(_csPin);
        Serial.println(_clkPin);
      }

		private:
			LedControl _lc;
			uint8_t _dataPin;
			uint8_t _csPin;
			uint8_t _clkPin;
			uint8_t _numDevices;
	};
} //namespace Component

#endif /* Max72XX_hpp */
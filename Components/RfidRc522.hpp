#ifndef RfidRc522_h
#define RfidRc522_h

#include "IComponent.hpp"

//Arduino install (SPI.h, MFRC522).h) from library manager.
//#include "MFRC522.h"
//https://arduino-france.site/rfid-rc522/
#include <SPI.h>
#include <MFRC522.h>
namespace Component {

	class RfidRc522: public IComponent {
		public:
			RfidRc522(uint8_t pinSDA, uint8_t pinSCK, uint8_t pinMOSI, uint8_t pinMISO, uint8_t pinIRQ, uint8_t pinGND, uint8_t pinRST, uint8_t pinVCC) {
				pinMode(_pin, INPUT);
			};

	//  	int Read(){
	//			return analogRead(_pin);
	//		};

			void Info() override {
        Serial.print("RfidRc522: ...");
      }

		private:
			uint8_t _pin;
	};
	
} //namespace Component

#endif /* RfidRc522_h */
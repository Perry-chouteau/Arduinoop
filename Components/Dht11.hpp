#ifndef Dht11_hpp
#define Dht11_hpp

#include "IComponent.hpp"

//Arduino install (dht/ada fruit) from library manager.
#include <DHT.h>
#include "Arduino.h"

namespace Component {

  class Dht11: public IComponent {
    public:
      Dht11(): _dht(2, DHT11) {

      };
      Dht11(uint8_t pin): _dht(pin, DHT11) {
        _pin = pin;
        pinMode(pin, INPUT);
        _dht.begin();
      }

      float ReadHumidity() {
        return _dht.readHumidity();
      }

      float ReadTemperature() {
        return _dht.readTemperature();
      }

      void Info() override {
        Serial.print("DHT11: ");
        Serial.println(_pin);
      }

    private:
      DHT _dht;
      uint8_t _pin;
  };

} //namespace Component

#endif /* Dht11_hpp */

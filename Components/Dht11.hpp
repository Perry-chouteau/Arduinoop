#ifndef Dht11_hpp
#define Dht11_hpp

//Arduino install (dht/ada fruit) from library manager.
#include <DHT.h>

class Dht11 {
  public:
  	Dht11(uint8_t pin): dht(pin, DHT11) {
      dht.begin();
		};

  	float ReadHumidity(){
      return dht.readHumidity();
    }
    float ReadTemperature() {
      return dht.readTemperature();
		};

  private:
    DHT dht;
};

#endif /* Dht11_hpp */
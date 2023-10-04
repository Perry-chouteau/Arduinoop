#ifndef WaterSensor_h
#define WaterSensor_h

class WaterSensor {
  public:
  	WaterSensor(uint8_t pin) {
			pinMode(_pin, INPUT);
		};

  	int Read(){
			return analogRead(_pin);
		};

  private:
  	uint8_t _pin;
};

#endif /* WaterSensor_h */
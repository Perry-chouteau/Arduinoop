/*#include "Components/Components.hpp"
#include "Arduino.h"

Dht11 dht(2);

void setup(){
  Serial.begin(9600);
}

void loop(){
  float h = dht.ReadHumidity();
  delay(100);
  float t = dht.ReadTemperature();
  delay(100);

  Serial.print("h: ");
  Serial.println(h);
  Serial.print("t: ");
  Serial.println(t);
}*/
#include <Vector.h>
#include <Array.h>

#include "Components/Components.hpp"
#include "Controllers/Controllers.hpp"
#include "Arduino.h"

Arduino::Uno<2> board;
Component::Dht11& dht11 = board.AddDht11(4);

void setup(){
  Serial.begin(115200);
  board.List();
}

void loop(){
  float h = dht11.ReadHumidity();
  float t = dht11.ReadTemperature();
  Serial.print("humidity: ");
  Serial.print(h);
  Serial.print(" , temperature: ");
  Serial.print(t);
  Serial.println();
  Serial.println("--------------------");
  delay(2000);
}
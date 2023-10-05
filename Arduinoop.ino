#include <Vector.h>

#include "Components/Components.hpp"
#include "Controllers/Controllers.hpp"
#include "Arduino.h"

Component::Dht11 dht(2);
Arduino::Uno board;

void setup(){
  Serial.begin(9600);
}

void loop(){
  Component::Dht11 dht2 = board.AddDht11(2);
}
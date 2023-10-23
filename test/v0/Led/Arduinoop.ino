#include <Vector.h>
#include <Array.h>

#include "Components/Components.hpp"
#include "Controllers/Controllers.hpp"
#include "Arduino.h"

Arduino::Uno<2> board;
Component::Led& led = board.AddLed(2);

void setup(){
  Serial.begin(115200);
  board.List();
}

void loop(){
  Serial.print("Board Size: ");
  Serial.println(board.Size());
  led.On();
  delay(1000);
  led.Off();
  delay(1000);
}
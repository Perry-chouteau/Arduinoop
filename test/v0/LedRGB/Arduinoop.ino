#include <Vector.h>
#include <Array.h>

#include "Components/Components.hpp"
#include "Controllers/Controllers.hpp"
#include "Arduino.h"

Arduino::Uno<2> board;
Component::LedRGB& ledRgb = board.AddLedRGB(11,10,9);

void setup(){
  Serial.begin(115200);
  board.List();
}

void loop(){
  Serial.print("Board Size: ");
  Serial.println(board.Size());
  ledRgb.DigitalWriteRGB(HIGH, LOW, LOW);
  delay(1000);
  ledRgb.DigitalWriteRGB(LOW, LOW, HIGH);
  delay(1000);
}
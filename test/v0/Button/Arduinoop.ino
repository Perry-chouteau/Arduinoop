#include <Vector.h>
#include <Array.h>

#include "Components/Components.hpp"
#include "Controllers/Controllers.hpp"
#include "Arduino.h"

Arduino::Uno<2> board;
Component::Button& button = board.AddButton(2);

void setup(){
  Serial.begin(115200);
  board.List();
}

void loop(){
  bool b = button.Read();

  Serial.print(b);
  Serial.println();
  Serial.println("--------------------");
  delay(500);
}
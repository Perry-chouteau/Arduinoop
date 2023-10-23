#include <Vector.h>
#include <Array.h>

#include "Components/Components.hpp"
#include "Controllers/Controllers.hpp"
#include "Arduino.h"

Arduino::Uno<2> board;
Component::Joystick& joystick = board.AddJoystick(A0,A1,2);

void setup(){
  Serial.begin(115200);
  board.List();
}

void loop(){
  int x = joystick.ReadX();
  int y = joystick.ReadY();
  bool b = joystick.ReadSW();

  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.print(b);
  Serial.println();
  Serial.println("--------------------");
//  delay(500);
}
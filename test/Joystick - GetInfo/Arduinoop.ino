#include "Components/Led.hpp"
#include "Components/LedRGB.hpp"
#include "Components/Joystick.hpp"
#include "Arduino.h"

Joystick  joystick(A0, A1, 2);

void setup(){
  Serial.begin(9600);
}

void loop(){
  int x = joystick.ReadX();
  int y = joystick.ReadY();
  bool sw = joystick.ReadSW();

  delay(100);
  Serial.print("x: ");
  Serial.println(x);
  Serial.print("y: ");
  Serial.println(y);
  Serial.print("sw: ");
  Serial.println(sw);
}
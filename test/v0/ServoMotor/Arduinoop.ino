#include <Vector.h>
#include <Array.h>

#include "Components/Components.hpp"
#include "Controllers/Controllers.hpp"
#include "Arduino.h"

Arduino::Uno<1> board;
Component::ServoMotor& servomotor = board.AddServoMotor(9);

void setup(){
  Serial.begin(115200);
  board.List();
  servomotor.Attach();
//  delay(2000);
}

#define MIN 0
#define MAX 180
int pos = 0;    // variable to store the servo position
//#define Left 60
//#define Right 140

void loop(){
//  int val = map(analogRead(A1), 0, 1023, 60, 140);
//  servomotor.Write(val);                  // sets the servo position according to the scaled value
//  delay(15);º
  for (pos = 60; pos <= 140 && pos <= MAX; pos += 1) { // goes from 0 degrees to 180 degrees
    Serial.println(pos);
    servomotor.Write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 140; pos >= 60 && pos >= MIN; pos -= 1) { // goes from 180 degrees to 0 degrees
    Serial.println(pos);
    servomotor.Write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
}
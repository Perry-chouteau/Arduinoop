#include <Vector.h>
#include <Array.h>

#include "Components/Components.hpp"
#include "Controllers/Controllers.hpp"
#include "Arduino.h"

Arduino::Uno<2> board;
Component::Max72XX& screen1 = board.AddMax72XX(12, 11, 10, 1);
Component::Joystick& joystick = board.AddJoystick(A0, A1, 2);
bool restart = false;

int p1[2] = {0, 0};

void setup(){
  Serial.begin(115200);
  board.List();
  screen1.Init();
}

void loop() {
    restart = (restart) ? Restart(screen1) : Start(screen1);
    delay(2000);
    //Build P1

//    Serial.println("hey");
    P1(screen1);
    delay(2000);
    Build(screen1);
    delay(2000);
    None(screen1);
    while (true) {
      int x = map(joystick.ReadX(), 0, 1023, 0, 7);
      int y = map(joystick.ReadY(), 0, 1023, 7, 0);
      screen1.Turn<ON>(0, x, y);
      delay(100);
      screen1.Turn<OFF>(0, x, y);
      delay(100);
      if (!joystick.ReadSW()) {
        p1[0] = x;
        p1[1] = y;
        screen1.Turn<ON>(0, x, y);
        delay(100);
        break;
      }
    }
    delay(2000);
    //Build P2
//    P2(screen1);
//    delay(2000);
//    Build(screen1);
//    delay(2000);
//    while (true) {
//      if (joystick.ReadSW()) {
//        int x = map(joystick.ReadX(), 0, 1023, 0, 8);
//        int y = map(joystick.ReadY(), 0, 1023, 0, 8);
//        Base2[x][y] = true;
//        break;
//      }
//    }
//    Home(screen1);
//    delay(1000);
//    Fight(screen1);
//    delay(1000);
}

void None(Component::Max72XX& max72xx) {
  max72xx.TurnRow(0, 0, B00000000);
  max72xx.TurnRow(0, 1, B00000000);
  max72xx.TurnRow(0, 2, B00000000);
  max72xx.TurnRow(0, 3, B00000000);
  max72xx.TurnRow(0, 4, B00000000);
  max72xx.TurnRow(0, 5, B00000000);
  max72xx.TurnRow(0, 6, B00000000);
  max72xx.TurnRow(0, 7, B00000000);
}
bool Start(Component::Max72XX& max72xx) {
  max72xx.TurnRow(0, 0, B00000000);
  max72xx.TurnRow(0, 1, B00110000);
  max72xx.TurnRow(0, 2, B00111000);
  max72xx.TurnRow(0, 3, B00111100);
  max72xx.TurnRow(0, 4, B00111100);
  max72xx.TurnRow(0, 5, B00111000);
  max72xx.TurnRow(0, 6, B00110000);
  max72xx.TurnRow(0, 7, B00000000);
  return true;
}

bool Restart(Component::Max72XX& max72xx) {
  max72xx.TurnRow(0, 0, B00000000);
  max72xx.TurnRow(0, 1, B00111000);
  max72xx.TurnRow(0, 2, B01000100);
  max72xx.TurnRow(0, 3, B10000010);
  max72xx.TurnRow(0, 4, B10000111);
  max72xx.TurnRow(0, 5, B10000010);
  max72xx.TurnRow(0, 6, B01000000);
  max72xx.TurnRow(0, 7, B00111000);
  return true;
}

void Pause(Component::Max72XX& max72xx) {
  max72xx.TurnRow(0, 0, B00000000);
  max72xx.TurnRow(0, 1, B01100110);
  max72xx.TurnRow(0, 2, B01100110);
  max72xx.TurnRow(0, 3, B01100110);
  max72xx.TurnRow(0, 4, B01100110);
  max72xx.TurnRow(0, 5, B01100110);
  max72xx.TurnRow(0, 6, B01100110);
  max72xx.TurnRow(0, 7, B00000000);
}

void P1(Component::Max72XX& max72xx) {
  max72xx.TurnRow(0, 0, B00000000);
  max72xx.TurnRow(0, 1, B11100010);
  max72xx.TurnRow(0, 2, B10010110);
  max72xx.TurnRow(0, 3, B11100010);
  max72xx.TurnRow(0, 4, B10000010);
  max72xx.TurnRow(0, 5, B10000010);
  max72xx.TurnRow(0, 6, B10000111);
  max72xx.TurnRow(0, 7, B00000000);
}

void P2(Component::Max72XX& max72xx) {
  max72xx.TurnRow(0, 0, B00000000);
  max72xx.TurnRow(0, 1, B11100110);
  max72xx.TurnRow(0, 2, B10010001);
  max72xx.TurnRow(0, 3, B11100001);
  max72xx.TurnRow(0, 4, B10000010);
  max72xx.TurnRow(0, 5, B10000100);
  max72xx.TurnRow(0, 6, B10000111);
  max72xx.TurnRow(0, 7, B00000000);
}

void Build(Component::Max72XX& max72xx) {
  max72xx.TurnRow(0, 0, B00010000);
  max72xx.TurnRow(0, 1, B00111000);
  max72xx.TurnRow(0, 2, B01111100);
  max72xx.TurnRow(0, 3, B11111000);
  max72xx.TurnRow(0, 4, B01111000);
  max72xx.TurnRow(0, 5, B00100100);
  max72xx.TurnRow(0, 6, B00000010);
  max72xx.TurnRow(0, 7, B00000001);
}

void Fight(Component::Max72XX& max72xx) {
  max72xx.TurnRow(0, 0, B00011000);
  max72xx.TurnRow(0, 1, B00110000);
  max72xx.TurnRow(0, 2, B01111100);
  max72xx.TurnRow(0, 3, B01011101);
  max72xx.TurnRow(0, 4, B00011111);
  max72xx.TurnRow(0, 5, B00100110);
  max72xx.TurnRow(0, 6, B01001100);
  max72xx.TurnRow(0, 7, B10000000);
}

void Home(Component::Max72XX& max72xx) {
  max72xx.TurnRow(0, 0, B00011000);
  max72xx.TurnRow(0, 1, B00100100);
  max72xx.TurnRow(0, 2, B01000010);
  max72xx.TurnRow(0, 3, B10000001);
  max72xx.TurnRow(0, 4, B10110001);
  max72xx.TurnRow(0, 5, B10110101);
  max72xx.TurnRow(0, 6, B10000101);
  max72xx.TurnRow(0, 7, B11111111);
}
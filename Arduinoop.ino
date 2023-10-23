#include <Vector.h>
#include <Array.h>

#include "Components/Components.hpp"
#include "Components/Icon/Max72XX.hpp"
#include "Controllers/Controllers.hpp"
#include "Arduino.h"

#define Base1 B00000001
#define Base2 B00000010
#define Attack1 B00000100
#define Attack2 B00001000

Arduino::Uno<2> board;
Component::Max72XX& screen = board.AddMax72XX(12, 11, 10, 1);
Component::Joystick& joystick = board.AddJoystick(A0, A1, 2);
byte info[8][8];
bool restart = false;

void setup(){
  Serial.begin(115200);
  board.List();
  screen.Init();
//  Serial.println(map[0][0] && Base1);
}

void loop() {
    restart = (restart) ? Restart(screen) : Start(screen);
    delay(2000);
    if (restart) { 
      None(screen);
    }

    //Build P1
    P1(screen);
    delay(2000);
    Build(screen);
    delay(2000);
    PlaceBoat(screen, Base1);
    delay(2000);

    //Build P2;
    P2(screen);
    delay(2000);
    Build(screen);
    delay(2000);
    PlaceBoat(screen, Base2);
    delay(2000);

    /*
      Atack
    */

    //P2 Attack;
    P1(screen);
    delay(2000);
    Fight(screen);
    delay(2000);
    Atack(screen, Attack2, Base2);
    delay(2000);

    //P1 Base;
    P2(screen);
    delay(2000);
    Home(screen);
    delay(2000);
    DisplayMask(screen, Base2);
    delay(2000);

}

void DisplayMask(Component::Max72XX& screen, byte base) {
  None(screen);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (((info[i][j] & base))) {
        screen.Turn<ON>(0, i, j);
      }
    }
  }
}

void PlaceBoat(Component::Max72XX& screen, byte base) {
  None(screen);
  for (int boatNb = 0; boatNb < 5;) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if ((info[i][j] & base) != 0) {
          screen.Turn<ON>(0, i, j);
        }
      }
    }
    int x = map(joystick.ReadX(), 0, 1023, 0, 7);
    int y = map(joystick.ReadY(), 0, 1023, 7, 0);
    screen.Turn<ON>(0, x, y);
    delay(100);
    screen.Turn<OFF>(0, x, y);
    delay(100);
    if (!joystick.ReadSW() && !(info[x][y] & base)) {
      info[x][y] += base;
      screen.Turn<ON>(0, x, y);
      delay(100);
      ++boatNb;
    }
  }
  delay(2000);
}

void Atack(Component::Max72XX& screen, byte atack, byte base) {
  while (true) {
    None(screen);
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if ((info[i][j] & atack) != 0) {
          screen.Turn<ON>(0, i, j);
        }
      }
    }
    int x = map(joystick.ReadX(), 0, 1023, 0, 7);
    int y = map(joystick.ReadY(), 0, 1023, 7, 0);
    screen.Turn<ON>(0, x, y);
    delay(100);
    screen.Turn<OFF>(0, x, y);
    delay(100);
    if (!joystick.ReadSW() && !(info[x][y] & atack)) {
      info[x][y] += atack;
      info[x][y] = info[x][y] & ~(base); // this doesn't work (I want it to set the bit of base on the uint8 to 0)
      screen.Turn<ON>(0, x, y);
      delay(100);
      break;
    }
  }
}
#include <Vector.h>
#include <Array.h>

#include "../../../Components/Components.hpp"
#include "../../../Components/Icon/Max72XX.hpp"
#include "../../../Controllers/Controllers.hpp"
#include "Arduino.h"

Arduino::Uno<2> board;
Component::Max72XX& screen = board.AddMax72XX(12, 11, 10, 1);
Component::Bluetooth& bluetooth = board.AddBluetouth();

void setup(){
  Serial.begin(115200);
  board.List();
  screen.Init();
}

void loop() {

}
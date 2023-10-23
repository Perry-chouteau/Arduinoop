#include "../Components.hpp"

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
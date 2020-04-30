//Provides implementation of playership class 
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#include "Sprite.h"
#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H
#include <stdint.h>


class PlayerShip{ private:
  Sprite sprite;
public:
  PlayerShip();
  void Draw();
  void UpdatePos(uint8_t x, uint8_t y);
  uint8_t Getx();
  uint8_t Gety();
};





#endif

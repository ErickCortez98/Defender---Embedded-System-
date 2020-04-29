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
  PlayerShip(uint16_t x, uint16_t y, const unsigned short* im, uint16_t w, uint16_t h): sprite(x, y, im, w, h) {}
  void Draw();
  void UpdatePos(uint16_t x, uint16_t y);
};





#endif

//Provides implementation of playership class 
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#include "Sprite.h"
#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H
#include <stdint.h>


class PlayerShip{ private:
  
public:
	Sprite sprite; // I changed this to public to be able to find the position of the ship
  PlayerShip();
  void Draw();
  void UpdatePos(uint16_t x, uint16_t y);
};





#endif

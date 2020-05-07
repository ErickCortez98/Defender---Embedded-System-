//Provides implementation of bullet class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/29/2020

#include "Sprite.h"
#include <stdint.h>
#include "PlayerShip.h"

#ifndef BULLET_H
#define BULLET_H

class Bullet{ 
	private:
  Sprite bulletSprite;
  int16_t x;
  int16_t start_x;
  uint8_t y;
  uint16_t color;
  direction_t dir;
  status_t status;

public:
	Bullet();
  ~Bullet();
  Bullet(int16_t new_x, uint8_t new_y, direction_t new_dir);
  void Draw();
  void UpdatePos(int16_t x, uint16_t y);
  int16_t Getx();
  uint8_t Gety();
  status_t GetStatus();
};


#endif

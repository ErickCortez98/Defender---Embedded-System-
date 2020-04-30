//Provides implementation of bullet class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/29/2020

#include "Sprite.h"
#include <stdint.h>
#ifndef BULLET_H
#define BULLET_H

typedef enum {dead,alive} status_t;

class Bullet{ 
	private:
  Sprite bulletSprite;
  status_t status;

public:
	Bullet();
  Bullet(uint8_t x, uint8_t y);
  void Draw();
  void UpdatePos(uint16_t x, uint16_t y);
  uint8_t Getx();
  uint8_t Gety();
  status_t GetStatus();
};


#endif

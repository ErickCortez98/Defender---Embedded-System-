//Provides implementation of bullet class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/29/2020

#include "Sprite.h"
#include <stdint.h>
#include "PlayerShip.h"

class Bullet{ 
	private:
  Sprite bulletSprite;

public:
	Bullet();
  void Draw();
  void UpdatePos(uint16_t x, uint16_t y);
	void fireBullet(PlayerShip Player);
};

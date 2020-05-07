#include <stdint.h>
#include "PlayerShip.h"

enum directionEnemyBullet {UpRight, UpLeft, DownLeft, DownRight, Up, Down, Left, Right};
#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H

class EnemyBullet{ 
	private:
	uint16_t player_x; //x location of the enemy when the bullets was fired
	uint8_t player_y;	//y location of the enemy when the bullets was fired
  uint16_t last_x;
	uint8_t last_y;
	int16_t x;
  uint8_t y;
  status_t status;
	directionEnemyBullet dirEnemyBullet; //enum that will tell us the direction of the bullet 
	float slope; //how many elements of y we move for every element of x or viceversa
	uint8_t collisionPlayer;
	uint8_t updatePositionSlow;
public:
	EnemyBullet(int16_t new_x, uint8_t new_y, uint16_t player_x, uint8_t player_y);
  /*~EnemyBullet();*/ //we probably don't need destructor
  void Draw(uint16_t player_x, uint8_t player_y);
  void UpdatePos(int16_t x, uint16_t y);
  int16_t Getx();
  uint8_t Gety();
  status_t GetStatus();
	void determineSlope(int16_t player_x, uint8_t player_y); //determines float slope of the bullet, how many y pixels we move per x pixel and its direction
	uint8_t checkCollisionPlayer(int16_t player_x, int8_t player_y);
	uint8_t getCollisionPlayer();
};


#endif

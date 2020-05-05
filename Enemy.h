//Provides implementation of enemy class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 5/01/2020

#include <stdint.h>
#include "Sprite.h"
#include "PlayerShip.h"
#include "List.h"
#include "Bullet.h"

class Enemy{
	private: 
		Sprite enemySprite;
		status_t status;
		int live; // enemies staring life: 50 points of life for enemy 1, 100 points of life for enemy 2
		int x;
    int Abs_x;
		uint8_t y;
    int last_mapx;
    uint8_t last_mapy;
		uint8_t updatePosition;
		uint8_t velocity; //we have different velocity depending on the enemy
		direction_t direction; //if enemy has direction right, then it spawns from the left, otherwise it spawns from the right
		uint8_t collisionPlayer; //variable that tell us if we have collisioned with the main player - 1 for collision
	public:
		Enemy(int x, uint8_t y, uint8_t typeEnemy, direction_t direction);//constructor, we specify the type of our enemy and its direction
		~Enemy(); //destructor of enemy class which allows to delete the enemy
		int getX();
		uint8_t getY();
		status_t getStatus();
		void setStatus(status_t newStatus);
		uint8_t getLive();
		void reduceLive(uint8_t liveReduction);
		void Draw(uint8_t hyper, direction_t playerShipDirection, List<Bullet> *BulletList, uint16_t player_x, uint8_t player_y);
		void UpdatePos(int x, uint16_t y);
		int8_t randomUpDownFn();
		bool checkCollision(List<Bullet> *BulletList); //function that checks the x position of all the bullets and compares them with the enemy to decide if there has been a collision
		uint8_t getVelocity();
    void DrawMap();
		uint8_t getCollisionPlayer(); // function that returns the status of the variable collisionPlayer
		uint8_t checkCollisionPlayer(int16_t player_x, int8_t player_y); //function that tell us if we have crashed against the main player  
};


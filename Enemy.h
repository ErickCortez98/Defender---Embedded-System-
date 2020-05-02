//Provides implementation of enemy class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 5/01/2020

#include <stdint.h>
#include "Sprite.h"

class Enemy{
	private: 
		Sprite enemySprite;
		status_t status;
		uint8_t live; // enemies staring life: 50 points of life for enemy 1, 100 points of life for enemy 2
		uint8_t x;
		uint8_t y;
		uint8_t updatePosition;
		uint8_t velocity; //we have different velocity depending on the enemy
	public:
		Enemy(uint8_t x, uint8_t y, uint8_t typeEnemy);//constructor, we specify the type of our enemy with it's initial live
		uint8_t getX();
		uint8_t getY();
		status_t getStatus();
		void setStatus(status_t newStatus);
		uint8_t getLive();
		void reduceLive(uint8_t liveReduction);
		void Draw();
		void UpdatePos(uint16_t x, uint16_t y);
		int8_t randomUpDownFn();
};

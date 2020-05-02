//Provides implementation of enemy class functions
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 5/01/2020

#include <stdint.h>
#include "Sprite.h"

class Enemy{
	private: 
		Sprite enemySprite;
		uint8_t status; //dead or alive --- 0 or 1
		uint8_t live; // enemies staring live: 50 points of live for enemy 1, 100 points of live for enemy 2
		uint8_t x;
		uint8_t y;
	public:
		Enemy(uint8_t x, uint8_t y, uint8_t typeEnemy);//constructor, we specify the type of our enemy with it's initial live
		uint8_t getX();
		uint8_t getY();
		uint8_t getStatus();
		void setStatus(uint8_t newStatus);
		uint8_t getLive();
		void reduceLive(uint8_t liveReduction);
		void Draw();
		void UpdatePos(uint16_t x, uint16_t y);
		int8_t randomUpDownFn();
};

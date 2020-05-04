//Provides implementation of playership class 
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#include "Sprite.h"
#include "C:\Keil_v5\EE319KwareSpring2020\inc\TM4C123gh6pm.h"

#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H
#include <stdint.h>

typedef enum {left,right} direction_t;

class PlayerShip{ private:
  Sprite Rsprite;
  Sprite Lsprite;
  Sprite HRsprite;
  Sprite HLsprite;
  int16_t x;
  uint8_t y;
  direction_t dir;
  bool hyper;
public:

  PlayerShip();
  void Draw();
  void UpdatePos(int16_t x, uint8_t y);
  int16_t Getx();
  uint8_t Gety();
  void ToggleDirection();
  direction_t GetDir();

  void ToggleHyper();
  bool GetHyper();
};





#endif

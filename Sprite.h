//Provides implementation of playership class 
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#ifndef SPRITE_H
#define SPRITE_H
#include <stdint.h>


//Sprite class to be used for any class that needs something drawn
class Sprite{ private:
  uint8_t x;      // x coordinate
  uint8_t y;      // y coordinate
  const unsigned short *image; // ptr->image
  uint8_t w;
  uint8_t h;
public:
  Sprite(){}
  Sprite(uint8_t init_x, uint8_t init_y, const unsigned short* init_im, uint8_t init_w, uint8_t init_h): x(init_x), y(init_y), image(init_im), w(init_w), h(init_h) {}
  void Draw();
  uint8_t Getx();
  uint8_t Gety();
  void UpdatePos(uint8_t new_x, uint8_t new_y);
};




#endif

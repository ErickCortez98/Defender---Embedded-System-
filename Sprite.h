//Provides implementation of playership class 
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#ifndef SPRITE_H
#define SPRITE_H
#include <stdint.h>


//Sprite class to be used for any class that needs something drawn
class Sprite{ private:
  uint16_t x;      // x coordinate
  uint16_t y;      // y coordinate
  const unsigned short *image; // ptr->image
  uint16_t w;
  uint16_t h;
public:
  Sprite(uint16_t init_x, uint16_t init_y, const unsigned short* init_im, uint16_t init_w, uint16_t init_h): x(init_x), y(init_y), image(init_im), w(init_w), h(init_h) {}
  void Draw();
  uint16_t Getx();
  uint16_t Gety();
  void UpdatePos(uint16_t new_x, uint16_t new_y);
};




#endif

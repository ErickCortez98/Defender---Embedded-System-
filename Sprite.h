//Provides implementation of playership class 
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/28/2020

#ifndef SPRITE_H
#define SPRITE_H
#include <stdint.h>


//Sprite class to be used for any class that needs something drawn
class Sprite{ private:
  const unsigned short *image; // ptr->image
  uint8_t w;
  uint8_t h;
public:
  Sprite(){}
  Sprite(const unsigned short* init_im, uint8_t init_w, uint8_t init_h): image(init_im), w(init_w), h(init_h) {}
  void Draw(uint8_t x, uint8_t y);
};




#endif

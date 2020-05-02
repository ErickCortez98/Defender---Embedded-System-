// images.h
// contains image buffers for defender
// Student names: Jaxon Coward, Erick Cortez
// Last modification date: 04/28/2020
// Capture image dimensions from BMP files

#include <stdint.h>
#ifndef __images_h
#define __images_h



// *************************** Images ***************************


//width 10, height 21
const unsigned short PlayerShipR[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0xD6BA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC,
 0xB1CC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x04DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x8BEC, 0x8BEC, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xD6BA, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x8BEC, 0xB133, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB133, 0xB133, 0x8BEC, 0x8BEC, 0x8BEC, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xB133, 0xB133, 0xB133, 0x8BEC, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0xB133, 0xB133,
 0xB133, 0x8BEC, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x5569, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x18D6, 0x04DF, 0x4AAF, 0xD5E0,
 0xB1CC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x18D6, 0x0000, 0x18D6, 0x18D6, 0x04DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000,

};

//width 10, height 21
const unsigned short PlayerShipL[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x18D6, 0x0000, 0x18D6, 0x18D6, 0x04DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x18D6, 0x04DF, 0x4AAF, 0xD5E0, 0xB1CC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x5569, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x5569, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB133, 0xB133,
 0xB133, 0x8BEC, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0xB133, 0xB133, 0xB133, 0x8BEC, 0x8BEC, 0x8BEC, 0x0000, 0x0000,
 0x0000, 0x0000, 0xB133, 0xB133, 0x8BEC, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0xB133, 0x8BEC, 0x8BEC,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xD6BA, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x5569, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x04DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC,
 0xB1CC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xD6BA, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000,

};


//width 10, height 28
const unsigned short HyperShipR[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0xFFDF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x2958, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC,
 0xB287, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x04DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x8BEC, 0x8BEC, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x8BEC, 0xB133, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB133, 0xB133, 0x8BEC, 0x8BEC, 0x8BEC, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xB133, 0xB133, 0xB133, 0x8BEC, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0xB133, 0xB133,
 0xB133, 0x8BEC, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x5569, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F5F, 0x5569, 0x5569, 0x5569,
 0x3EF9, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F5F, 0x04DF, 0xB287, 0x4E11, 0x3EF9, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x18F6, 0x18F6, 0xB287, 0x5569, 0x18F6, 0x18F6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F5F, 0x60FD, 0xB287, 0x5569, 0x18F6,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x60FD, 0x5569, 0x3F5F, 0x18F6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569,
 0x5569, 0x18F6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3EF9, 0x3F5F, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x3EF9, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,

};





//width 10, height 28
const unsigned short HyperShipL[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0xFFDF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x2958, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC,
 0xB287, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x04DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x8BEC, 0x8BEC, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x8BEC, 0xB133, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB133, 0xB133, 0x8BEC, 0x8BEC, 0x8BEC, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xB133, 0xB133, 0xB133, 0x8BEC, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0xB133, 0xB133,
 0xB133, 0x8BEC, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8BEC, 0x5569, 0x8BEC, 0x8BEC, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F5F, 0x5569, 0x5569, 0x5569,
 0x3EF9, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F5F, 0x04DF, 0xB287, 0x4E11, 0x3EF9, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x18F6, 0x18F6, 0xB287, 0x5569, 0x18F6, 0x18F6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3F5F, 0x60FD, 0xB287, 0x5569, 0x18F6,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x60FD, 0x5569, 0x3F5F, 0x18F6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569,
 0x5569, 0x18F6, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3EF9, 0x3F5F, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x3EF9, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,

};






// width 5, height 11
/*const unsigned short BulletImage[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000,
 0x4E11, 0x8CA0, 0x4E11, 0x0000, 0x0000, 0x8CA0, 0x8CA0, 0x8CA0, 0x0000, 0x0000, 0x8CA0, 0x8CA0, 0x8CA0, 0x0000, 0x0000, 0x0000,
 0x8CA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x4E11, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,

};*/

//width 12, height 13
const unsigned short Enemy_1[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x5569, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x5569, 0x5569, 0x5569, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x061F, 0x0000, 0x0000, 0x061F, 0x061F, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x5569, 0x5569, 0x5569, 0x5569, 0x5569,
 0x061F, 0x061F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x061F, 0x5569, 0x5569, 0x061F, 0x061F, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x5569, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569,
 0x0000, 0x0000, 0x5569, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,

};

//width 8, height 15
const unsigned short Enemy_2[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x5569, 0x3F5F, 0x297A, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x3F5F, 0x0000, 0x5569, 0x0000, 0x0000,
 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x3F5F, 0x297A, 0x5569, 0x0000, 0x0000,
 0x0000, 0x0000, 0x5569, 0x3F5F, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000,
 0x0000, 0x0000, 0x5569, 0x3F5F, 0x297A, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x3F5F, 0x5569, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,

};



//width 5, height 25
const unsigned short BulletImage[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x4E11, 0x0000, 0x0000, 0x0000,
 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000,
 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569,
 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x4E11, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x4E11, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x4E11, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000,
 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x5569, 0x0000, 0x0000, 0x0000, 0x0000, 0x4E11, 0x0000, 0x0000, 0x0000, 0x0000,
 0x4E11, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,

};








#endif /* __images_h */

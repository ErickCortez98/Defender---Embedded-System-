//Provides implementation of terrain
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/30/2020


#include <stdint.h>
#include "ST7735.h"
#include "PlayerShip.h"

#ifndef TERRAIN_H
#define TERRAIN_H

#define SCREENWIDTH 160
#define TERRAINSIZE 640
#define MAPSIZE 80

static uint16_t TerrainVelocity = 0;
static uint16_t TerrainIndex = 0;
static uint16_t LastTerrainIndex = TERRAINSIZE;


const uint8_t TerrainData[TERRAINSIZE] = {
  4,5,6,7,8,9,8,7,6,5,4,3,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,4,5,6,7,8,9,8,7,6,5,4,3,
  3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,15,
  14,13,12,11,10,9,8,7,8,9,10,11,12,13,14,
  13,12,11,10,9,8,7,6,5,4,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,5,6,7,
  8,9,10,11,10,9,8,7,6,5,4,5,6,7,8,9,10,11,
  12,13,14,15,16,17,18,17,16,15,14,13,12,11,
  10,11,12,13,14,15,16,17,18,19,18,17,16,15,
  14,13,12,11,10,9,8,9,10,11,12,13,14,15,16,
  15,14,13,12,11,12,13,14,15,16,17,18,19,20,
  19,18,17,16,15,14,15,16,17,18,19,18,17,16,
  15,14,13,12,11,10,9,8,9,10,11,12,13,14,15,
  16,15,14,13,12,11,10,9,8,7,6,5,4,3,3,3,3,3,
  3,3,3,3,3,3,3,4,5,6,7,8,9,10,11,12,13,14,15,
  16,17,18,19,20,19,18,17,16,15,14,13,12,11,10,
  11,12,13,14,15,16,17,16,15,14,13,12,11,10,9,8,
  7,6,5,4,3,3,3,3,3,3,3,3,3,3,3,3,4,5,6,7,8,9,
  10,11,12,11,10,9,8,7,6,5,4,3,4,5,6,7,8,9,10,
  11,12,13,14,15,16,17,18,17,16,15,14,13,12,11,
  10,9,8,7,6,5,4,3,4,5,6,7,8,7,6,5,4,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,4,5,6,7,8,9,10,11,
  12,13,14,15,16,17,16,15,14,13,12,11,10,9,10,
  11,12,13,14,15,16,17,18,19,20,19,18,17,18,19,
  20,19,18,17,18,19,20,19,18,17,16,15,14,13,12,
  11,10,11,12,13,14,15,16,17,18,17,16,15,14,13,
  12,11,10,9,8,7,6,7,8,9,10,11,12,13,14,15,16,
  17,18,19,20,19,18,17,16,15,14,13,12,11,10,9,
  8,7,6,5,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3

};










const uint8_t TerrainMapData[MAPSIZE] = {
  2,1,0,0,0,0,0,0,0,1,2,1,2,3,4,3,2,3,2,1,1,2,3,4,5,4,5,4,3,4,5,4,3,2,3,2,2,3,4,5,4,4,3,2,1,2,2,3,4,3,2,1,0,0,0,0,0,0,1,2,3,4,4,5,4,5,4,4,3,4,5,4,3,2,1,0,0,0,0,1

};

void DrawTerrain();

void UpdateTerrainIndex(direction_t dir, bool hyper);

void DrawMap();

void DrawUI();



#endif

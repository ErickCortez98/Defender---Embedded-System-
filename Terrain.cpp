//Provides implementation of terrain
// Program written by: Jaxon Coward, Erick I. Cortez Valdez
//Date created: 4/30/2020


#include "Terrain.h"

void DrawTerrain(){
  for(int i = 0; i < SCREENWIDTH; i++){
    
    int index = TerrainIndex + i;
    int last_index = LastTerrainIndex + i;
    
    if(index >= TERRAINSIZE){
      index -= TERRAINSIZE;
    }
    if(last_index >= TERRAINSIZE){
      last_index -= TERRAINSIZE;
    }
    
    ST7735_DrawPixel(TerrainData[last_index], i, ST7735_BLACK);//clear the last drawn terrain
    ST7735_DrawPixel(TerrainData[index], i, ST7735_YELLOW);
  }
}

void UpdateTerrainIndex(int16_t mod_index){
  LastTerrainIndex = TerrainIndex;
  TerrainIndex += mod_index;//need to modify for overflow and underflow
  if(TerrainIndex >= TERRAINSIZE){
    TerrainIndex -= TERRAINSIZE;
  }
}


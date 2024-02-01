#include "raylib.h"
#include <cstdint>

#ifndef TILES_HPP
#define TILES_HPP

typedef uint8_t tileType;
typedef uint16_t depth;

typedef struct tile{

    Vector2 position = {1, 1};
    depth depth = 0;
    tileType type = 0;

    Rectangle frameRec = { 16.0f, 0.0f, 16, 16 };

} tile;

//TODO: relocate

void drawTilesDebug(Texture2D texture, tile tile){

    for (int i = 0; i < 16; i++){

        for (int j = 0; j < 16; j++){

            DrawTextureRec(texture, tile.frameRec, {tile.position.x * i * 16, tile.position.y * j * 16}, WHITE);

        }
               

    }
    

}


#endif
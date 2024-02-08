#include "engine/perlin.hpp"
#include "raylib.h"

#include <cstdint>
#include <vector>

#ifndef TILES_HPP
#define TILES_HPP

typedef uint8_t tileType;
typedef uint16_t depth;

typedef struct tile {

    Vector2 position = {1, 1};
    depth depth = 0;
    tileType type = 0;

    Rectangle frameRec = {16.0f, 0.0f, 16, 16};

} tile;

// Just a tile vector
typedef std::vector<std::vector<tile>> tileMap;

tileMap generateTileMap(int size);

// TODO: relocate

void drawTilesDebug(Texture2D texture, tileMap tile, int size, Camera2D camera);

#endif
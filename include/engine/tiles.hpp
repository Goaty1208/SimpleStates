#include "engine/perlin.hpp"
#include "raylib.h"

#include <cstdint>
#include <vector>

#ifndef TILES_HPP
#define TILES_HPP

const int TileSize = 32;

typedef uint8_t tileType;
typedef uint16_t depth;

const Rectangle MountainRec = {TileSize * 3, 0.0f, TileSize, TileSize};
const Rectangle GrassRec = {TileSize * 2, 0.0f, TileSize, TileSize};
const Rectangle SandRec = {TileSize, 0.0f, TileSize, TileSize};
const Rectangle WaterRec = {0, 0.0f, TileSize, TileSize};

typedef struct tile {

    Vector2 position = {1, 1};
    depth depth = 0;
    tileType type = 0;

    Rectangle frameRec = {TileSize, 0.0f, TileSize, TileSize};

} tile;

// Just a tile vector
typedef std::vector<std::vector<tile>> tileMap;

tileMap generateTileMap(int size);

// TODO: relocate

void drawTilesDebug(Texture2D texture, tileMap tile, int size, Camera2D camera);

#endif
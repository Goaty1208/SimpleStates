#include "engine/tiles.hpp"

tileMap generateTileMap(int size) {

    float offsetX = static_cast<float>(rand()) / RAND_MAX * 1000.0f;
    float offsetY = static_cast<float>(rand()) / RAND_MAX * 1000.0f;
    float scale = 64;

    tileMap map;

    map.resize(size, std::vector<tile>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            float perlinValue = perlinGeneration(offsetX + i / scale, offsetY + j / scale);
            map[i][j].position = {(float)i, (float)j};

            if (perlinValue <= 0.35f) {

                map[i][j].type = 3;

            } else if (perlinValue <= 0.5f && perlinValue <= 0.51f) {

                map[i][j].type = 2;

            } else if (perlinValue <= 0.51f && perlinValue <= 0.52f) {

                map[i][j].type = 1;

            } else {

                map[i][j].type = 0;
            }

            switch (map[i][j].type) {
            case 0:
                map[i][j].frameRec = WaterRec;
                break;
            case 1:
                map[i][j].frameRec = SandRec;
                break;
            case 2:
                map[i][j].frameRec = GrassRec;
                break;
            case 3:
                map[i][j].frameRec = MountainRec;
                break;
            }
        }
    }

    return map;
}

void drawTilesDebug(Texture2D texture, tileMap tile, int size, Camera2D camera) {

    Vector2 worldSize = GetScreenToWorld2D({(float)GetScreenWidth(), (float)GetScreenHeight()}, camera);
    Vector2 screenZero = GetScreenToWorld2D({0.0f, 0.0f}, camera);

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            if (tile[i][j].position.x * TileSize + TileSize >= screenZero.x && tile[i][j].position.x * TileSize <= worldSize.x && tile[i][j].position.y * TileSize + TileSize >= screenZero.y && tile[i][j].position.y * TileSize <= worldSize.y) {

                DrawTextureRec(texture, tile[i][j].frameRec, {tile[i][j].position.x * TileSize, tile[i][j].position.y * TileSize}, WHITE);
            }
        }
    }
}

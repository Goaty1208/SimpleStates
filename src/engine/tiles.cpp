#include "engine/tiles.hpp"

tileMap generateTileMap(int size) {

    float offsetX = static_cast<float>(rand()) / RAND_MAX * 1000.0f;
    float offsetY = static_cast<float>(rand()) / RAND_MAX * 1000.0f;
    float scale = static_cast<float>(rand()) / RAND_MAX * 80.0f;

    tileMap map;

    map.resize(size, std::vector<tile>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            float perlinValue = perlinGeneration(offsetX + i / scale, offsetY + j / scale);
            map[i][j].position = {(float)i, (float)j};
            map[i][j].type = (perlinValue < 0.5f) ? 0 : 1;

            map[i][j].frameRec = {16.0f * map[i][j].type, 0.0f, 16, 16};
        }
    }

    return map;
}

void drawTilesDebug(Texture2D texture, tileMap tile, int size, Camera2D camera) {

    Vector2 worldSize = GetScreenToWorld2D({(float)GetScreenWidth(), (float)GetScreenHeight()}, camera);
    Vector2 screenZero = GetScreenToWorld2D({0.0f, 0.0f}, camera);

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            if (tile[i][j].position.x * 16 + 16 >= screenZero.x && tile[i][j].position.x * 16 <= worldSize.x && tile[i][j].position.y * 16 + 16 >= screenZero.y && tile[i][j].position.y * 16 <= worldSize.y) {

                DrawTextureRec(texture, tile[i][j].frameRec, {tile[i][j].position.x * 16, tile[i][j].position.y * 16}, WHITE);
            }
        }
    }
}

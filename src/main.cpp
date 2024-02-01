#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "engine/tiles.hpp"

int main(){

	InitWindow(1000, 1000, "Test 1");

	Texture2D tileTexture = LoadTexture("assets/textures/tilesTileSet.png");

	tile Tile;

    Camera2D camera = { 0 };
    camera.zoom = 1.0f;

	while (!WindowShouldClose()){

		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
            Vector2 delta = GetMouseDelta();
            delta = Vector2Scale(delta, -1.0f/camera.zoom);

            camera.target = Vector2Add(camera.target, delta);
        }

        // Zoom based on mouse wheel
        float wheel = GetMouseWheelMove();
        if (wheel != 0){
            // Get the world point that is under the mouse
            Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
            
            // Set the offset to where the mouse is
            camera.offset = GetMousePosition();

            // Set the target to match, so that the camera maps the world space point 
            // under the cursor to the screen space point under the cursor at any zoom
            camera.target = mouseWorldPos;

            // Zoom increment
            const float zoomIncrement = 0.125f;

            camera.zoom += (wheel*zoomIncrement);
            if (camera.zoom < zoomIncrement) camera.zoom = zoomIncrement;
        }

		BeginDrawing();
	
        BeginMode2D(camera);

            ClearBackground(BLACK);

			drawTilesDebug(tileTexture, Tile);


		EndMode2D();
        
        DrawFPS(1,1);
   
        EndDrawing();


	}
	
	CloseWindow();

	return 0;
}
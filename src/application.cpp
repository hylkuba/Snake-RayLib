/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#include "application.h"

CApplication::CApplication() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");

    SetTargetFPS(TARGET_FPS);
}

CApplication::~CApplication() {
    CloseWindow();
}

int CApplication::run() {

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("SNAKE GAME!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    return 0;
}

void CApplication::initGame() {

}

void CApplication::updateGame() {

}

void CApplication::drawGame() {
    
}
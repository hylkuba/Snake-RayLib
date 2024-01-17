/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#include "application.h"

CApplication::CApplication() 
    : gameOver(false) {

    snake = CSnake();
    fruit = CFruit();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");

    SetTargetFPS(TARGET_FPS);
}

CApplication::~CApplication() {
    CloseWindow();
}

int CApplication::run() {

    // Main game loop
    while (!WindowShouldClose()) {
        updateGame();

        drawGame();
    }

    return 0;
}

void CApplication::updateGame() {

}

void CApplication::drawGame() {
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);

    if(!gameOver) {
        //drawGridLines();

        snake.draw();

        fruit.draw();
    } else {
        DrawText("PRESS [ENTER] TO PLAY AGAIN", SCREEN_WIDTH / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, SCREEN_HEIGHT / 2 - 50, 20, GRAY);
    }

    EndDrawing();
}

void CApplication::drawGridLines() {

    for (int i = 0; i < SQUARE_COUNT + 1; i++)
    {
        float offset = SQUARE_SIZE * i;
        DrawLineV((Vector2){offset, 0}, (Vector2){offset, SCREEN_HEIGHT}, GRID_COLOR);
    }

    for (int i = 0; i < SQUARE_COUNT + 1; i++)
    {
        float offset = SQUARE_SIZE * i;
        DrawLineV((Vector2){0, offset}, (Vector2){SCREEN_WIDTH, offset}, LIGHTGRAY);
    }
}
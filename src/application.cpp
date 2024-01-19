/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#include "application.h"

#include "pos.h"
#include <iostream>

CApplication::CApplication() 
    : gameOver(false), fruitActive(false), moveAllowed(true), lastUpdateTime(0.0),
        refreshInterval(INIT_INTERVAL) {

    snake = CSnake();
    fruit = CFruit();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game");

    SetTargetFPS(TARGET_FPS);
}

CApplication::~CApplication() {
    CloseWindow();
}

int CApplication::run() {

    // Loop for games
    while(true) {

        // Main game loop
        while (!WindowShouldClose()) {
            // Update the game if interval condition is fullfilled
            if(eventTriggered(refreshInterval)) {
                updateGame();

                if(snake.win()) {
                    DrawText("CONGRATULATIONS!! YOU WON!!", SCREEN_WIDTH / 2 - MeasureText("CONGRATULATIONS!! YOU WON!!", 20) / 2, SCREEN_HEIGHT / 2, 20, GRAY);
                    break;
                }
                moveAllowed = true;
            }

            checkKeyPresses();

            drawGame();

            if(gameOver) {
                break;
            }
        }

        // If window was closed by user, end application
        if(!gameOver) {
            break;
        } else {
            bool enter = false;

            while(!WindowShouldClose()) {
                if(IsKeyPressed(KEY_ENTER)) {
                    enter = true;
                    break;
                }
                BeginDrawing();
                ClearBackground(BACKGROUND_COLOR);
                DrawText("PRESS [ENTER] TO PLAY AGAIN", SCREEN_WIDTH / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, SCREEN_HEIGHT / 2, 20, GRAY);
                EndDrawing();
            }

            if(!enter) {
                break;
            } else {
                reset();
            }
        }
    }

    return 0;
}

void CApplication::updateGame() {
    if(!fruitActive) {
        fruit.generateNewPos(snake.getBody());
        fruitActive = true;
    }
    snake.update();

    if(checkEatenFruit()) {
        snake.grow();
        fruit.generateNewPos(snake.getBody());
        refreshInterval *= DIFF_MULTIPLIER;

        if(refreshInterval < INTERVAL_CAP) {
            refreshInterval = INTERVAL_CAP;
        }
    }

    if(snake.getPosX() < 0 || snake.getPosX() >= CELL_COUNT 
        || snake.getPosY() < 0 || snake.getPosY() >= CELL_COUNT) {

        gameOver = true;   
    }

    if(snake.checkBodyHit()) {

        gameOver = true;
    }
}

void CApplication::drawGame() {
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);

    if(GRID_LINES) {
        drawGridLines();
    }

    snake.draw();
    fruit.draw();

    EndDrawing();
}

void CApplication::drawGridLines() {

    for (int i = 0; i < CELL_COUNT + 1; i++)
    {
        float offset = CELL_SIZE * i;
        DrawLineV((Vector2){offset, 0}, (Vector2){offset, SCREEN_HEIGHT}, GRID_COLOR);
    }

    for (int i = 0; i < CELL_COUNT + 1; i++)
    {
        float offset = CELL_SIZE * i;
        DrawLineV((Vector2){0, offset}, (Vector2){SCREEN_WIDTH, offset}, GRID_COLOR);
    }
}

bool CApplication::eventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

void CApplication::checkKeyPresses() {
    if (IsKeyPressed(KEY_UP) && snake.getDir().getPosY() != 1 && moveAllowed) {
        snake.changeDir({0, -1});
        moveAllowed = false;
    }
    if (IsKeyPressed(KEY_DOWN) && snake.getDir().getPosY() != -1 && moveAllowed) {
        snake.changeDir({0, 1});
        moveAllowed = false;
    }
    if (IsKeyPressed(KEY_LEFT) && snake.getDir().getPosX() != 1 && moveAllowed) {
        snake.changeDir({-1, 0});
        moveAllowed = false;
    }
    if (IsKeyPressed(KEY_RIGHT) && snake.getDir().getPosX() != -1 && moveAllowed) {
        snake.changeDir({1, 0});
        moveAllowed = false;
    }
}

bool CApplication::checkEatenFruit() {
    if(snake.getBody()[0] == fruit.getPos()) {
        return true;
    }
    return false;
}

void CApplication::reset() {
    snake = CSnake();
    fruit = CFruit();

    gameOver = false;
    fruitActive = false;
    moveAllowed = true;
    lastUpdateTime = 0.0;
    refreshInterval = INIT_INTERVAL;
}
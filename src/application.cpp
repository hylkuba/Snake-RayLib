/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#include "application.h"

#include "pos.h"

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

    // Main game loop
    while (!WindowShouldClose()) {
        // Update the game if interval condition is fullfilled
        if(eventTriggered(refreshInterval)) {
            updateGame();
            moveAllowed = true;
        }

        checkKeyPresses();

        drawGame();

        if(gameOver) {
            while(!WindowShouldClose()) {
                if (IsKeyPressed(KEY_ENTER)) {
                    gameOver = false;
                    // TODO reset everything
                }
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
    }

    if(snake.getPosX() < 0 || snake.getPosX() >= SQUARE_COUNT 
        || snake.getPosY() < 0 || snake.getPosY() >= SQUARE_COUNT) {
        
        gameOver = true;   
    }

    if(snake.checkBodyHit()) {
        gameOver = true;
    }
}

void CApplication::drawGame() {
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);

    if(!gameOver) {
        if(GRID_LINES) {
            drawGridLines();
        }

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
    if(snake.getBody()[0] == CPos{fruit.getPosX(), fruit.getPosY()}) {
        return true;
    }
    return false;
}
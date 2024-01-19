/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 19.01.2024
*/

#include "game.h"

CGame::CGame() : moveAllowed(true) {
    
    snake = CSnake();
    fruit = CFruit();
    fruit.generateNewPos(snake.getBody());
}

bool CGame::update(double &refreshInterval) {
    moveAllowed = true;

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

        return false;
    }

    if(snake.checkBodyHit()) {

        return false;
    }

    return true;
}

void CGame::draw() {
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);

    if(GRID_LINES) {
        drawGridLines();
    }

    snake.draw();
    fruit.draw();

    EndDrawing();
}

void CGame::drawGridLines() {

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

void CGame::checkKeyPresses() {
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

bool CGame::checkEatenFruit() {
    if(snake.getBody()[0] == fruit.getPos()) {
        return true;
    }
    return false;
}
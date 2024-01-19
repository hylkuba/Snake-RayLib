/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 19.01.2024
*/

#include "game.h"

#include <string>

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

        // Check if snake used whole map
        if(snake.win()) {
            congratulate();
            return false;
        }

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

    for (int i = 0; i <= CELL_COUNT + 1; i++) {
        float offset = CELL_SIZE * i;
        DrawLineV((Vector2){offset, MARGIN}, (Vector2){offset, SCREEN_HEIGHT + MARGIN}, GRID_COLOR);
    }

    for (int i = 0; i <= CELL_COUNT + 1; i++) {
        float offset = CELL_SIZE * i;
        DrawLineV((Vector2){MARGIN, offset}, (Vector2){SCREEN_WIDTH + MARGIN, offset}, GRID_COLOR);
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

void CGame::congratulate() {
    double start = GetTime();
    while(GetTime() - start < CONGRATULATE_TIME && !WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);

        int diff = start - GetTime() + CONGRATULATE_TIME;
        DrawText("CONGRATULATIONS", SCREEN_WIDTH / 2 - MeasureText("CONGRATULATIONS", 20) / 2, SCREEN_HEIGHT / 2, 20, GRAY);
        std::string message = "YOU CAN START AGAIN IN: " + std::to_string(diff);
        DrawText(message.c_str(), SCREEN_WIDTH / 2 - MeasureText(message.c_str(), 20) / 2, SCREEN_HEIGHT / 2 + 20, 20, GRAY);
        EndDrawing();
    }
}
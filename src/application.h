/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#pragma once

#include "raylib.h"
#include "constants.h"
#include "snake.h"
#include "fruit.h"

class CApplication {
public:
    CApplication();

    ~CApplication();

    int run();

private:
    void updateGame();

    void drawGame();

    void drawGridLines();

    bool gameOver;

    CSnake snake;
    CFruit fruit;
};
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

    bool eventTriggered(double interval);

    void checkKeyPresses();

    bool checkEatenFruit();

    bool gameOver;

    bool fruitActive;

    bool moveAllowed;

    double lastUpdateTime;

    double refreshInterval;

    CSnake snake;
    CFruit fruit;
};
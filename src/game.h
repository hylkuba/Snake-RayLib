/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 19.01.2024
*/

#pragma once

#include "snake.h"
#include "fruit.h"

class CGame {
public:
    CGame();

    bool update(double &refreshInterval);

    void draw();

    void checkKeyPresses();

    bool checkEatenFruit();
private:
    void drawGridLines();

    bool fruitActive;

    bool moveAllowed;

    CSnake snake;
    CFruit fruit;
};
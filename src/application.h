/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#pragma once

#include "raylib.h"
#include "constants.h"
#include "game.h"

class CApplication {
public:
    CApplication();

    ~CApplication();

    int run();

private:
    bool eventTriggered(double interval);

    bool gameOver;

    double lastUpdateTime;

    double refreshInterval;
};
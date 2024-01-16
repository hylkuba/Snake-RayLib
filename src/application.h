/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#pragma once

#include "raylib.h"
#include "constants.h"

class CApplication {
public:
    CApplication();

    ~CApplication();

    int run();

private:
    void initGame();

    void updateGame();

    void drawGame();
};
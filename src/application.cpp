/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#include "application.h"

#include <iostream>

CApplication::CApplication() 
    : gameOver(false), lastUpdateTime(0.0),
        refreshInterval(INIT_INTERVAL) {
    InitWindow(SCREEN_WIDTH + MARGIN * 2, SCREEN_HEIGHT + MARGIN * 2, "Snake Game");

    SetTargetFPS(TARGET_FPS);
}

CApplication::~CApplication() {
    CloseWindow();
}

int CApplication::run() {

    // Loop for games
    while(true) {
        
        CGame game = CGame();

        // Main game loop
        while (!WindowShouldClose()) {
            // Update the game if interval condition is fullfilled
            if(eventTriggered(refreshInterval)) {
                gameOver = !game.update(refreshInterval);
            }

            if(gameOver) {
                break;
            }

            game.checkKeyPresses();

            game.draw();
        }

        // If window was closed by user, end application
        if(!gameOver) {
            break;
        } else {

            // Otherwise wait till user presses ENTER
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
            }
        }
    }

    return 0;
}

bool CApplication::eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}
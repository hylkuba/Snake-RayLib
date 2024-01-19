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
    /**
     * @brief Sets initial values and creates window
     * 
     */
    CApplication();

    /**
     * @brief Closes the window
     * 
     */
    ~CApplication();

    /**
     * @brief Controls the flow of application
     * 
     * @return int 
     */
    int run();

private:
    /**
     * @brief Checks whether certain amount of time has passed
     * 
     * @param interval Refresh value in ms how often the game should be updated
     * @return true If interval value has passed
     * @return false Otherwise
     */
    bool eventTriggered(double interval);

    // Used in run(). Checks whether the game was ended by user or by game loop
    bool gameOver;

    // Last time in ms when the game was refreshed
    double lastUpdateTime;

    // Time in ms of how often should the game be refreshed
    double refreshInterval;
};
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

    ~CGame() = default;

    /**
     * @brief Updates game loop. Checks for hits and moves a snake
     * 
     * @param refreshInterval Decreases when snake eats fruit
     * @return true If snake is OK
     * @return false If snake hit tail or wall
     */
    bool update(double &refreshInterval);

    /**
     * @brief Draw snake and fruit
     * 
     */
    void draw();

    /**
     * @brief Check if arrow keys were pressed and change snake's direction accordingly
     * 
     */
    void checkKeyPresses();

    /**
     * @brief Checks if snake's head is on same position as fruit
     * 
     * @return true If snake ate
     * @return false Otherwise
     */
    bool checkEatenFruit();
private:
    /**
     * @brief Draws grid lines.
     * Function is called only if GRID_LINES is true
     * 
     */
    void drawGridLines();

    /**
     * @brief Print congratulations and wait CONGRATULATE_TIME
     * 
     */
    void congratulate();

    /**
     * @brief Writes score below the map
     *  Score is the size of snake's body
     * 
     */
    void writeScore();

    // Forbids multiple moves at the same time due to keyboard delays
    bool moveAllowed;

    CSnake snake;
    CFruit fruit;
};
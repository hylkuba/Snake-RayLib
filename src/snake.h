/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#pragma once

#include "constants.h"
#include "pos.h"
#include "raylib.h"

#include <deque>

class CSnake : public CPos {
public:
    /**
     * @brief Create snake. Generate his body with SNAKE_INIT_LENGTH
     *  and set its position to the middle of the screen
     * 
     */
    CSnake();

    ~CSnake() = default;

    /**
     * @brief Inserts into the body of snake last position
     * 
     */
    void grow();

    /**
     * @brief Draws the body of the snake
     * 
     */
    void draw();

    /**
     * @brief Moves the snake in his direction. Removes last element
     *  of body and adds new one
     * 
     */
    void update();

    /**
     * @brief Changes direction to specified move argument
     * 
     * @param move New direction
     */
    void changeDir(CPos move);

    /**
     * @brief Returns snake's direction
     * 
     * @return CPos Direction
     */
    CPos getDir();

    /**
     * @brief Checks if snake's head hit the tail
     * 
     * @return true 
     * @return false 
     */
    bool checkBodyHit();

    /**
     * @brief Returns body of the snake
     * 
     * @return std::deque<CPos> 
     */
    std::deque<CPos> getBody();

    /**
     * @brief Checks if snake takes the whole screen
     *  In other words that the whole map has been used
     * 
     * @return true 
     * @return false 
     */
    bool win();

    /**
     * @brief Returns the size of body
     * 
     * @return size_t
     */
    unsigned int getSize();

private:
    Color m_head_color;

    CPos dir;
    
    std::deque<CPos> body;
};
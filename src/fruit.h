/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#pragma once

#include "pos.h"

#include <deque>

class CFruit : public CPos {
public: 
    CFruit() = default;

    ~CFruit() = default;

    /**
     * @brief Draws fruit
     * 
     */
    void draw();

    /**
     * @brief Generates new position for fruit that is not in forbiddenPos dequeue
     * 
     * @param forbiddenPos dequeu of snake's body
     */
    void generateNewPos(std::deque<CPos> forbiddenPos);

private:
    /**
     * @brief Get the range where fruits can be spawned.
     * Range is decided based on difficulty chosen
     * 
     * @return std::pair<int, int> 
     */
    std::pair<int, int> getRange();
};
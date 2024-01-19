/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#pragma once

#include "pos.h"

#include <deque>

class CFruit : public CPos {
public: 
    void draw();

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
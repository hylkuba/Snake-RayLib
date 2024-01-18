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
};
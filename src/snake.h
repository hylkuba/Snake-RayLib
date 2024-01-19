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
    CSnake();

    ~CSnake() = default;

    void grow();

    void draw();

    void update();

    void changeDir(CPos move);

    CPos getDir();

    bool checkBodyHit();

    std::deque<CPos> getBody();

    bool win();

private:
    Color m_head_color;

    CPos dir;
    
    std::deque<CPos> body;
};
/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#pragma once

#include "constants.h"
#include "pos.h"
#include "raylib.h"

class CSnake : public CPos {
public:
    CSnake();

    ~CSnake() = default;

    void grow();

private:
    int m_length;
    int m_speed;
    Color m_color;
    Color m_head_color;
};
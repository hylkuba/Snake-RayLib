/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#include "snake.h"

#include <iostream>

CSnake::CSnake()
      : m_length(SNAKE_INIT_LENGTH),
        m_speed(SNAKE_SPEED),
        m_color(SNAKE_COLOR),
        m_head_color(SNAKE_HEAD_COLOR) {

    for (int i = 0; i < SNAKE_INIT_LENGTH; i++) {
        CPos pos(SNAKE_START_POS_X, SNAKE_START_POS_Y + i);
        body.push_back(pos);
    }
    
    setPos(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void CSnake::grow() {
    m_length++;
}

void CSnake::draw() {
    for (std::deque<CPos>::iterator it = body.begin(); it != body.end(); ++it) {
        Rectangle segment = Rectangle{it->getPosX() * (float)SQUARE_SIZE, it->getPosY() * (float)SQUARE_SIZE, (float)SQUARE_SIZE, (float)SQUARE_SIZE};
        DrawRectangleRounded(segment, SNAKE_ROUNDNESS, 10, SNAKE_COLOR);
    }
}
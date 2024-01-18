/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#include "snake.h"

#include <algorithm>

CSnake::CSnake()
      : m_length(SNAKE_INIT_LENGTH),
        m_speed(SNAKE_SPEED),
        m_color(SNAKE_COLOR),
        m_head_color(SNAKE_HEAD_COLOR) {

    for (int i = 0; i < SNAKE_INIT_LENGTH; i++) {
        CPos pos(SNAKE_START_POS_X, SNAKE_START_POS_Y + i);
        body.push_back(pos);
    }

    dir.setPos(0, -1);
    
    setPos(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void CSnake::grow() {
    m_length++;
    body.push_back(body.back());
}

void CSnake::draw() {
    for (std::deque<CPos>::iterator it = body.begin(); it != body.end(); ++it) {
        Rectangle segment = Rectangle{it->getPosX() * (float)SQUARE_SIZE, it->getPosY() * (float)SQUARE_SIZE, (float)SQUARE_SIZE, (float)SQUARE_SIZE};
        DrawRectangleRounded(segment, SNAKE_ROUNDNESS, 10, SNAKE_COLOR);
    }
}

void CSnake::update() {
    body.push_front(body[0] + dir);
    setPos(body.front());
    body.pop_back();
}

void CSnake::changeDir(CPos move) {
    dir = move;
}

CPos CSnake::getDir() {
    return dir;
}

std::deque<CPos> CSnake::getBody() {
    return body;   
}

bool CSnake::checkBodyHit() {
    std::deque<CPos> headlessBody = body;
    headlessBody.pop_front();

    for (size_t i = 0; i < headlessBody.size(); i++) {
        if (getPos() == headlessBody[i]) {
            return true;
        }
    }
    return false;
}
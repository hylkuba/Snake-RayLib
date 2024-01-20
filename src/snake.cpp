/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#include "snake.h"

#include <algorithm>

CSnake::CSnake()
      : m_head_color(SNAKE_HEAD_COLOR) {

    for (int i = 0; i < SNAKE_INIT_LENGTH; i++) {
        CPos pos(SNAKE_START_POS_X, SNAKE_START_POS_Y + i);
        body.push_back(pos);
    }

    dir.setPos(0, -1);
    
    setPos(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void CSnake::grow() {
    body.push_back(body.back());
}

void CSnake::draw() {
    unsigned char opacity = 255;

    // Draw head
    Rectangle segment = Rectangle{body[0].getPosX() * (float)CELL_SIZE + MARGIN,
            body[0].getPosY() * (float)CELL_SIZE + MARGIN, (float)CELL_SIZE, (float)CELL_SIZE};
    
    DrawRectangleRounded(segment, SNAKE_ROUNDNESS, 10, SNAKE_HEAD_COLOR);
    
    // Draw tail
    for (size_t i = 1; i < body.size(); i++) {
        Rectangle segment = Rectangle{body[i].getPosX() * (float)CELL_SIZE + MARGIN,
            body[i].getPosY() * (float)CELL_SIZE + MARGIN, (float)CELL_SIZE, (float)CELL_SIZE};

        DrawRectangleRounded(segment, SNAKE_ROUNDNESS, 10, (Color) { SNAKE_COLOR_R, SNAKE_COLOR_G, SNAKE_COLOR_B, opacity });
        
        // For each segment of body, decrease the opacity of tail for more natural visuals
        if(opacity > 50) {
            opacity -= 5;
        }
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

bool CSnake::win() {
    return body.size() == CELL_COUNT * CELL_COUNT;
}

unsigned int CSnake::getSize() {
    return body.size();
}
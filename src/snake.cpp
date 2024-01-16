/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#include "snake.h"

CSnake::CSnake()
      : m_length(SNAKE_INIT_LENGTH),
        m_speed(SNAKE_SPEED),
        m_color(SNAKE_COLOR),
        m_head_color(SNAKE_HEAD_COLOR) {
    setPos(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void CSnake::grow() {
    m_length++;
}
/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/  

#pragma once

class CPos {
public:
    CPos(int x = 0, int y = 0) {
        m_posX = x;
        m_posY = y;
    }

    int getPosX() {
        return m_posX;
    }

    int getPosY() {
        return m_posY;
    }

    void setPos(int x, int y) {
        m_posX = x;
        m_posY = y;
    }

private:
    int m_posX;
    int m_posY;
};
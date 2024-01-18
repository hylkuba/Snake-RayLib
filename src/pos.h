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

    bool operator<(const CPos& other) const {
        if (m_posX < other.m_posX) {
            return true;
        } else if (m_posX > other.m_posX) {
            return false;
        }
        return m_posY < other.m_posY;
    }
    
    bool operator==(const CPos& other) const {
        return (m_posX == other.m_posX) && (m_posY == other.m_posY);
    }

    CPos operator+(const CPos& other) const {
        return CPos(m_posX + other.m_posX, m_posY + other.m_posY);
    }

private:
    int m_posX;
    int m_posY;
};
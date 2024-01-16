/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

class CPos {
public:
    int getPosX();
    int getPosY();

    void setPos(int x, int y) {
        m_posX = x;
        m_posY = y;
    }

private:
    int m_posX;
    int m_posY;
};
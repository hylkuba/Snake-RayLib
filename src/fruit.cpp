/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

#include "fruit.h"
#include "constants.h"
#include "raylib.h"

#include <random>
#include <algorithm>

void CFruit::draw() {
    DrawCircle(getPosX() * SQUARE_SIZE + SQUARE_SIZE / 2, getPosY() * SQUARE_SIZE + SQUARE_SIZE / 2, SQUARE_SIZE / 4, FRUIT_COLOR);
}

void CFruit::generateNewPos(const std::deque<CPos> forbiddenPos) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> range(0, SQUARE_COUNT - 1);
    int x = range(gen);
    int y = range(gen);

    CPos curr = {x, y};
    auto it = std::find(forbiddenPos.begin(), forbiddenPos.end(), curr);
    // Check if the generated positions are in the forbidden set
    while (it != forbiddenPos.end()) {
        x = range(gen);
        y = range(gen);
        curr = {x, y};
        it = std::find(forbiddenPos.begin(), forbiddenPos.end(), curr);
    }
    setPos(x, y);
}
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
    DrawCircle(getPosX() * CELL_SIZE + CELL_SIZE / 2 + MARGIN, getPosY() * CELL_SIZE + CELL_SIZE / 2 + MARGIN, CELL_SIZE / 4, FRUIT_COLOR);
}

void CFruit::generateNewPos(const std::deque<CPos> forbiddenPos) {

    std::random_device rd;
    std::mt19937 gen(rd());

    std::pair<int, int> fruitRange = getRange();

    std::uniform_int_distribution<int> range(fruitRange.first, fruitRange.second);
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

std::pair<int, int> CFruit::getRange() {
    std::pair<int, int> result;
    switch(GAME_DIFF) {
        case 1:
            result = {2, CELL_COUNT - 3};
            break;
        case 2:
            result = {1, CELL_COUNT - 2};
            break;
        case 3:
            result = {0, CELL_COUNT - 1};
            break;
    }

    return result;
}
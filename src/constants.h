/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

// Set difficulty (1 easy, 2 medium, 3 hard)
#define GAME_DIFF 1

// Game constants
#define TARGET_FPS 60
#define CELL_SIZE 30
#define CELL_COUNT 20 
#define GRID_LINES true
#define INIT_INTERVAL 0.2
#define DIFF_MULTIPLIER 0.95
#define INTERVAL_CAP 0.1

// Screen constants
#define SCREEN_WIDTH (CELL_COUNT * CELL_SIZE)
#define SCREEN_HEIGHT (CELL_COUNT * CELL_SIZE)
#define BACKGROUND_COLOR (Color){ 32, 17, 59, 100 } // Purpleish
#define GRID_COLOR (Color) { 200, 200, 200, 50 } // Light gray

// Snake
#define SNAKE_INIT_LENGTH 3
#define SNAKE_START_POS_X (CELL_SIZE / 2)
#define SNAKE_START_POS_Y (CELL_SIZE / 2)
#define SNAKE_ROUNDNESS 0.9

// Snake colors (pinkish)
#define SNAKE_COLOR_R 245
#define SNAKE_COLOR_G 194
#define SNAKE_COLOR_B 194
#define SNAKE_HEAD_COLOR PINK

// Fruit
#define FRUIT_COLOR ORANGE
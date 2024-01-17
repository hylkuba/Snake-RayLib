/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 16.01.2024
*/

// Game constants
#define TARGET_FPS 60
#define SQUARE_SIZE 30
#define SQUARE_COUNT 30 

// Screen constants
#define SCREEN_WIDTH (SQUARE_COUNT * SQUARE_SIZE)
#define SCREEN_HEIGHT (SQUARE_COUNT * SQUARE_SIZE)
#define BACKGROUND_COLOR (Color){ 32, 17, 59, 200 } // Purpleish
#define GRID_COLOR LIGHTGRAY

// Snake
#define SNAKE_INIT_LENGTH 3
#define SNAKE_SPEED 1
#define SNAKE_COLOR (Color) { 245, 194, 194, 200 } // Pinkish
#define SNAKE_HEAD_COLOR DARKBLUE
#define SNAKE_START_POS_X (SQUARE_SIZE / 2)
#define SNAKE_START_POS_Y (SQUARE_SIZE / 2)
#define SNAKE_ROUNDNESS 0.9

// Fruit
#define FRUIT_COLOR ORANGE
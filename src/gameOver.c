#include "gameOver.h"

#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>



bool GameOver(Snake *snake, int max_y, int max_x){
    int headX = snake->body[0].x;
    int headY = snake->body[0].y;
    
    return (headX <= 0 || headX >= max_x - 1|| headY <= 0 || headY >= max_y - 1);
}
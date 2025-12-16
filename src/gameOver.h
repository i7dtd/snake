#ifndef MAP_H 
#define MAP_H

#include <stdbool.h>

typedef struct {
    int y;
    int x;
} Point;

typedef struct {
    Point body[100];
    int length;
    int dir_x;
    int dir_y;
} Snake;

bool GameOver(Snake *snake, int max_y, int max_x);

#endif

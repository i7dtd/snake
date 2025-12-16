#ifndef SNAKE_H
#define SNAKE_H

#include <stdbool.h>
#include <ncurses.h>

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

void SnakeUpdate(Snake *snake, int max_y, int max_x, int key, bool *game_over);

void SnakeDraw(WINDOW *win, Snake *snake);

#endif

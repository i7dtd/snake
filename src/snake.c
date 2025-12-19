#include "snake.h"
#include <ncurses.h>

/* Update snake position and check collisions */
void SnakeUpdate(Snake *snake, int max_y, int max_x, int key, bool *game_over){
    int oldDirX = snake->dir_x;
    int oldDirY = snake->dir_y;
    
    // Handle directional input
    if (key == KEY_UP || key == 'w') {
        snake->dir_y = -1; snake ->dir_x = 0;
    } else if (key == KEY_DOWN || key == 's') {
        snake->dir_y = 1; snake ->dir_x = 0;
    } else if (key == KEY_LEFT || key == 'a') {
        snake->dir_y = 0; snake ->dir_x = -1;
    } else if (key == KEY_RIGHT || key == 'd') {
        snake->dir_y = 0; snake ->dir_x = 1;
    } 
    
    // Prevent 180-degree turns
    if (snake->dir_y == -oldDirY && snake->dir_x == -oldDirX) {
        snake->dir_x = oldDirX;
        snake->dir_y = oldDirY;
    }
    
    // Calculate new head position
    Point head = snake->body[0];
    Point newHead = {head.y + snake->dir_y, head.x + snake->dir_x};
    
    // Wall collision check
    if (newHead.y <= 0  || newHead.y >= max_y || newHead.x <= 0 || newHead.x >= max_x) {
        *game_over = true;
        return;
    }

    // Self-collision check
    for (int i = 1; i < snake->length - 1; i++){
        if (newHead.y == snake->body[i].y && newHead.x == snake->body[i].x) {
            *game_over = true;
            return;
        }
    }
    
    // Move body segments forward
    for (int i = snake->length - 1; i > 0; i--){
        snake->body[i] = snake->body[i - 1];
    }
    
    // Apply new head position
    snake -> body[0] = newHead;
}


/* Draw snake body in game window */
void SnakeDraw(WINDOW *win, Snake *snake){
    wattron(win, COLOR_PAIR(1));
    
    for (int i = 0; i < snake->length; i++){
        mvwaddch(win, snake->body[i].y, snake->body[i].x, ACS_BLOCK);
    }
    
    wattroff(win, COLOR_PAIR(1));
}

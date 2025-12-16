#include "food.h"

#include <ncurses.h>
#include <stdlib.h>




void Food(Point *food, Snake *snake,int max_y, int max_x){
    while (true) { 
        food->y = rand() % (max_y - 2) + 1;
        food->x = rand() % (max_x - 2) + 1;
        
        int isFree = 1;
        
        for (int i = 0; i < snake->length; i++) {
            if (snake->body[i].y == food->y && snake->body[i].x == food->x) {
                isFree = 0;
                break;
            }
        }
        
        if (isFree) {
            break;
        }
    }
    
}

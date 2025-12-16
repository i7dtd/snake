#include "map.h"

#include <ncurses.h>


WINDOW *Map(int height, int width){
    int xMax; int yMax;
    getmaxyx(stdscr, yMax, xMax);
    
    WINDOW *win = newwin(height, width, (yMax / 2) - (height / 2), (xMax / 2) - (width / 2));
        
    box(win, 0, 0);
    return win;
}

#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>


// void Map(){
//     int world[COLS - 2 * 5];
//     for (int i = 0; i < COLS - 2 * 5; i++){
//         world[i] = rand() % LINES/2 + 1;
//     }
// }

int main(void){

    int snake;
    int y = 11, x = 11;
    
    initscr();
    keypad(stdscr, 1);
    noecho();
    curs_set(0);
    
    // a = getch();
    printw("Prees F1 to exit");
    
    
    int height; int width; int start_y; int start_x;
    height = 10;
    width = 20;
    start_x = start_y = 10;
    
    WINDOW * win = newwin(height, width, start_x, start_y);
    refresh();
    
    box(win, 0, 0);
    wprintw(win, "BOX");
    wrefresh(win);
    
   
    char map_data[10][20] = {
            "####################",
            "#                  #",
            "#                  #",
            "#                  #",
            "#                  #",
            "#                  #",
            "#                  #",
            "#                  #",
            "####################",
        };

    while ((snake = getch()) != KEY_F(1)) {
        clear();
        
        int map_height = 10;
        int map_width = 20;
        int view_x = 0; // Смещение по X
        int view_y = 0; // Смещение по Y

        
        for (int y = 0; y < map_height && view_y + y < map_height; y++) {
            for (int x = 0; x < map_width && view_x + x < map_width; x++) {
                mvaddch(y, x, map_data[view_y + y][view_x + x]);
                // if (x == '#' || y == '#'){
                //     printw("u heat the wall");
                //     return 1;
                // }
            }
        }
 
        
        if (snake == KEY_UP) y--;
        else if (snake == 'w') y--;
        else if (snake == KEY_DOWN) y++;
        else if (snake == 's') y++;
        else if (snake == KEY_RIGHT) x++;
        else if (snake == 'd') x++;
        else if (snake == KEY_LEFT) x--;
        else if (snake == 'a') x--;
        
        // if ("")
        
        mvaddch(y, x, '@');
        // if (y++ == '#') {
        //     printw("u heat the wall");
        // }
    }
    
    
    
    getch();
    
    endwin();
    
    
    return 0;
}

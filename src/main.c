#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "map.h"
#include "snake.h"
#include "food.h"
#include "gameOver.h"

#define HEIGHT 10
#define WIDTH 10



bool GameOver(Snake *snake, int max_y, int max_x){
    int headX = snake->body[0].x;
    int headY = snake->body[0].y;
    
    return (headX <= 0 || headX >= max_x - 1|| headY <= 0 || headY >= max_y - 1);
}

int main(void){
    /* basic start */
    initscr();
    cbreak();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    noecho();
    refresh();
    timeout(100);
    
    srand(time(NULL)); // for random generate food
    
    /* hide cursor */
    // noecho();
    curs_set(0);
    /* create exit */
    keypad(stdscr, 1);
    printw("Prees F1 to exit");
    
    Point food;
    // snake.dir_x = 11;
    // snake.dir_y = 11;
    int winHeight = 20;
    int winWidth = 40;
    WINDOW *win = Map(winHeight, winWidth); 
    wtimeout(win, 333);
    keypad(win, TRUE);
    Snake snake;
    snake.length = 3;
    snake.dir_x = 1;
    snake.dir_y = 0;
    
    snake.body[0] = (Point){10,10};
    snake.body[1] = (Point){10,9};
    snake.body[2] = (Point){10,8};

    Food(&food, &snake, winHeight, winWidth);
 
    bool game_over = false;
    int score = 0;
    while (!game_over) {
        int key = wgetch(win);
        
        Point head = snake.body[0];
        if (head.y == food.y && head.x == food.x) {
            snake.length++;
            score++;
            Food(&food, &snake, winHeight, winWidth);
        }
        
        SnakeUpdate(&snake, winHeight  , winWidth ,key, &game_over); 
        
        if (GameOver(&snake, winHeight , winWidth )){
            printf("Game over\n");
            break;
        }
        
        werase(win);            // clear win
        box(win, 0, 0);         // draw borders
        mvwprintw(win, 0, 1, "[Score %d]",score);
        SnakeDraw(win, &snake);
        wattron(win, COLOR_PAIR(2));
        mvwaddch(win, food.y, food.x, '*');
        wattroff(win, COLOR_PAIR(2));   
        wrefresh(win);          // ncurses -> terminal ??
    }
    
    
    // game over scene
    clear();
    mvprintw(LINES/2, COLS/2-5, "GAME OVER!");    
    mvprintw(LINES/2 + 1, COLS/2-4, "Score %d", score);
    refresh();
    sleep(2);
    getch();
    
    
    delwin(win);
    endwin();
    
    return 0;
}

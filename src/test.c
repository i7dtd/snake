// #include <ncurses.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include <string.h>
// #include "time.h"
// #include <unistd.h>

// #define HEIGHT 10
// #define WIDTH 10



// WINDOW *Map(int height, int width){
//     int xMax; int yMax;
//     getmaxyx(stdscr, yMax, xMax);
    
//     WINDOW *win = newwin(height, width, (yMax / 2) - (height / 2), (xMax / 2) - (width / 2));
        
//     box(win, 0, 0);
//     // wrefresh(win);
//     return win;
// }



// typedef struct {
//     int y;
//     int x;
// } Point;

// typedef struct {
//     Point body[100];
//     int length;
//     int dir_x;
//     int dir_y;
// } Snake;



// void Food(Point *food, Snake *snake,int max_y, int max_x){
//     int validPos = 0;
//     while (true) { 
//         food->y = rand() % (max_y - 2) + 1;
//         food->x = rand() % (max_x - 2) + 1;
        
//         int isFree = 1;
        
//         for (int i = 0; i < snake->length; i++) {
//             if (snake->body[i].y == food->y && snake->body[i].x == food->x) {
//                 isFree = 0;
//                 break;
//             }
//         }
        
//         if (isFree) {
//             break;
//         }
//     }
    
// }
// // TODO: error snake moving 
// void SnakeUpdate(Snake *snake, int max_y, int max_x, int key, bool *game_over){
//     int oldDirX = snake->dir_x;
//     int oldDirY = snake->dir_y;
    
//     // game keybindings
//     if (key == KEY_UP || key == 'w') {
//         snake->dir_y = -1; snake ->dir_x = 0;
//         // snake->dir_y = 1; 
//     } else if (key == KEY_DOWN || key == 's') {
//         snake->dir_y = 1; snake ->dir_x = 0;
//         // snake->dir_y = -1; 
//     } else if (key == KEY_LEFT || key == 'a') {
//         snake->dir_y = 0; snake ->dir_x = -1;
//         // snake ->dir_x = -1;
//     } else if (key == KEY_RIGHT || key == 'd') {
//         snake->dir_y = 0; snake ->dir_x = 1;
//         // snake ->dir_x = 1;
//     } 
//     //else {
//     //     return;
//     // }
    
//     // ingore snake moving back
//     if (snake->dir_y == -oldDirY && snake->dir_x == -oldDirX) {
//         snake->dir_x = oldDirX;
//         snake->dir_y = oldDirY;
//     }
    
    
    
//     // new head position
//     Point head = snake->body[0];
//     Point newHead = {head.y + snake->dir_y, head.x + snake->dir_x};
    
//     // game over if snake hit the wall
//     if (newHead.y <= 0  || newHead.y >= max_y || newHead.x <= 0 || newHead.x >= max_x) {
//         *game_over = true;
//         return;
//     }

//     // game over if snake hit tail
//     for (int i = 1; i < snake->length - 1; i++){
//         if (newHead.y == snake->body[i].y && newHead.x == snake->body[i].x) {
//             *game_over = true;
//             return;
//         }
//     }
    
//     // snake moving/animation
//     for (int i = snake->length - 1; i > 0; i--){
//         snake->body[i] = snake->body[i - 1];
//     }
    
//     snake -> body[0] = newHead;
// }

// void SnakeDraw(WINDOW *win, Snake *snake){
//     wattron(win, COLOR_PAIR(1));
    
//     for (int i = 0; i < snake->length; i++){
//         mvwaddch(win, snake->body[i].y, snake->body[i].x, 0xDB);
//     }
    
//     wattroff(win, COLOR_PAIR(1));
// }


// bool GameOver(Snake *snake, int max_y, int max_x){
//     int headX = snake->body[0].x;
//     int headY = snake->body[0].y;
    
//     return (headX <= 0 || headX >= max_x - 1|| headY <= 0 || headY >= max_y - 1);
// }

// int main(void){
//     /* basic start */
//     initscr();
//     cbreak();
//     start_color();
//     init_pair(1, COLOR_GREEN, COLOR_BLACK);
//     init_pair(2, COLOR_RED, COLOR_BLACK);
//     noecho();
//     refresh();
//     timeout(100);
    
//     srand(time(NULL)); // for random generate food
    
//     /* hide cursor */
//     // noecho();
//     curs_set(0);
//     /* create exit */
//     keypad(stdscr, 1);
//     printw("Prees F1 to exit");
    
//     Point food;
//     // snake.dir_x = 11;
//     // snake.dir_y = 11;
//     int winHeight = 20;
//     int winWidth = 40;
//     WINDOW *win = Map(winHeight, winWidth); 
//     wtimeout(win, 333);
//     keypad(win, TRUE);
//     Snake snake;
//     snake.length = 3;
//     snake.dir_x = 1;
//     snake.dir_y = 0;
    
//     snake.body[0] = (Point){10,10};
//     snake.body[1] = (Point){10,9};
//     snake.body[2] = (Point){10,8};

//     Food(&food, &snake, winHeight, winWidth);
 
//     bool game_over = false;
//     int score = 0;
//     while (!game_over) {
//         int key = wgetch(win);
        
//         Point head = snake.body[0];
//         if (head.y == food.y && head.x == food.x) {
//             snake.length++;
//             score++;
//             Food(&food, &snake, winHeight, winWidth);
//         }
        
//         SnakeUpdate(&snake, winHeight  , winWidth ,key, &game_over); 
        
//         if (GameOver(&snake, winHeight , winWidth )){
//             printf("Game over\n");
//             break;
//         }
        
//         werase(win);            // clear win
//         box(win, 0, 0);         // draw borders
//         mvwprintw(win, 0, 1, "[Score %d]",score);
//         SnakeDraw(win, &snake);
//         wattron(win, COLOR_PAIR(2));
//         mvwaddch(win, food.y, food.x, '*');
//         wattroff(win, COLOR_PAIR(2));   
//         wrefresh(win);          // ncurses -> terminal ??
        
//         // usleep(333333);
//     }
    
    
//     // game over scene
//     clear();
//     mvprintw(LINES/2, COLS/2-5, "GAME OVER!");    
//     mvprintw(LINES/2 + 1, COLS/2-4, "Score %d", score);
//     refresh();
//     sleep(2);
    
    
//     getch();
//     delwin(win);
//     endwin();
    
//     return 0;
// }




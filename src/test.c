#include <ncurses.h>
#include <stdbool.h>

#define HEIGHT 10
#define WIDTH 10



WINDOW *Map(int height, int width){
    int xMax; int yMax;
    getmaxyx(stdscr, yMax, xMax);
    
    WINDOW *win = newwin(height, width, (yMax / 2) - (height / 2), (xMax / 2) - (width / 2));
        
    box(win, 0, 0);
    // wrefresh(win);
    return win;
}



typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point body[100];
    int length;
    int dir_x;
    int dir_y;
} Snake;

// TODO: error snake moving 
void SnakeUpdate(Snake *snake, int max_y, int max_x, int key){
    // game keybindings
    if (key == KEY_UP || key == 'w') {
        snake->dir_y = -1; snake ->dir_x = 0;
        // snake->dir_y = 1; 
    } else if (key == KEY_DOWN || key == 's') {
        snake->dir_y = 1; snake ->dir_x = 0;
        // snake->dir_y = -1; 
    } else if (key == KEY_LEFT || key == 'a') {
        snake->dir_y = 0; snake ->dir_x = -1;
        // snake ->dir_x = -1;
    } else if (key == KEY_RIGHT || key == 'd') {
        snake->dir_y = 0; snake ->dir_x = 1;
        // snake ->dir_x = 1;
    } else {
        return;
    }
    
    // new head position
    Point head = snake->body[0];
    Point newHead = {head.y + snake -> dir_y, head.x + snake -> dir_x};
    
    
    // snake moving/animation
    for (int i = snake -> length - 1; i > 0; i--){
        snake -> body[i] = snake -> body[i - 1];
    }
    
    snake -> body[0] = newHead;
}

void SnakeDraw(WINDOW *win, Snake *snake){
    for (int i = 0; i < snake->length; i++){
        mvwaddch(win, snake->body[i].x, snake->body[i].y, '@');
    }
}

int main(void){
    /* basic start */
    initscr();
    cbreak();
    noecho();
    refresh();
    timeout(100);
    
    /* hide cursor */
    // noecho();
    curs_set(0);
    /* create exit */
    keypad(stdscr, 1);
    printw("Prees F1 to exit");
    
    
    // snake.dir_x = 11;
    // snake.dir_y = 11;
    int winHeight = 20;
    int winWidth = 40;
    WINDOW *win = Map(winHeight, winWidth); 
    keypad(win, TRUE);
    Snake snake;
    snake.length = 1;
    snake.dir_x = 1;
    snake.dir_y = 0;
    
    snake.body[0] = (Point){10,10};
    // snake.body[1] = (Point){10,10};
    // snake.body[2] = (Point){10,10};

    while (true) {
        int key = wgetch(win);
        
        SnakeUpdate(&snake, winHeight - 1, winWidth - 1,key); 
        
        werase(win);            // clear win
        box(win, 0, 0);         // draw borders
        SnakeDraw(win, &snake);
        wrefresh(win);          // ncurses -> terminal ??
    }
    
    delwin(win);
    endwin();
    
    return 0;
}




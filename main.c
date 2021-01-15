#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "source/structure.h"
#include "source/gamerules.h"
#include "source/front.h"

int main()
{
    initscr();
    //noecho();
    cbreak();
    draw_board();
    main_loop();
    getch();
    endwin();
}

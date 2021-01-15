#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <stdbool.h>

#include "source/structure.h"
#include "source/gamerules.h"
#include "source/front.h"

int main()
{
   // initscr();
    //noecho();
    //cbreak();
    
    gameInit();
    
    printf("Test\n");
    printf("%d %d %d\n", getChessPiece(1,0).type,  getChessPiece(1,0).color,  getChessPiece(1,0).moveFunctionPointer(1,1,0,0,2));
    printf("%d %d %d\n", getChessPiece(0,0).type,  getChessPiece(0,0).color,  getChessPiece(0,0).moveFunctionPointer(1,0,0,0,2));
    
    //draw_board();
    //main_loop();
    getch();
    endwin();
}

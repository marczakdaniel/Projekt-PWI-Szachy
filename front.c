#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#define b_b 88
void draw_board();

int main()
{
    initscr();
    noecho();
    cbreak();
    draw_board();
    getch();
    endwin();
}
void draw_board()
{
    start_color();
    char board[9][9];
    WINDOW *playing_board = newwin(41,97,LINES/2-21,COLS/2-48);

    char piece[3][4] ={
                    {' ','(',')',' '},
                    {' ',')','(',' '},
                    {'/','_','_','\\'}
    };
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++)
        {
            mvaddch(i,j,piece[i][j]);
        }
    
    // RYSOWANIE PLANSZY
    
    init_pair(1,COLOR_YELLOW,COLOR_BLACK); // linie kolor
    init_pair(2,COLOR_WHITE,b_b); // background kolor
    init_pair(3,COLOR_WHITE,239);
    wbkgd(playing_board,COLOR_PAIR(2));
    wattron(playing_board,COLOR_PAIR(1));
    box(playing_board,0,0);
    for(int y = 5 ; y < 48; y += 5) // podzial poziomy
    {
        mvwhline(playing_board,y,1,0,95);
    }
    for(int x = 12 ; x < 96; x+=12) // podzial pionowy
    {
        mvwvline(playing_board,0,x,0,40);
    }
    for(int x = 12 ; x < 96; x+=12)mvwhline(playing_board,40,x,ACS_BTEE,1); // laczenia dolne
    for(int x = 12 ; x < 96; x+=12)mvwhline(playing_board,0,x,ACS_TTEE,1); // laczenia gorne
    for(int y = 5 ; y < 40; y += 5)mvwvline(playing_board,y,96,ACS_RTEE,1); // laczenia prawe
    for(int y = 5 ; y < 40; y += 5)mvwvline(playing_board,y,0,ACS_LTEE,1); // laczenia lewe
    for(int i = 12; i < 96; i+=12)
        for(int j = 5; j < 40; j+=5)    // laczenia wewnetrzne
                mvwaddch(playing_board,j,i,ACS_PLUS);
    wattroff(playing_board,COLOR_PAIR(1));
    wattron(playing_board,COLOR_PAIR(3));
    int temp;
    for(int j = 1;j < 40; j+=5)
    {
        switch (j%2)
        {
            case 0:
                for(int i = 13 ; i < 96; i+=24)
                {   
                    move(j,i);
                    for(int y = 0; y < 4; y++)
                        for(int x = 0;x < 11;x++)
                        {
                            mvwaddch(playing_board,y+j,x+i,' ');
                        }
                }
                break;
            case 1:
                for(int i = 1 ; i < 96; i+=24)
                    {   
                        move(j,i);
                        for(int y = 0; y < 4; y++)
                            for(int x = 0;x < 11;x++)
                            {
                                mvwaddch(playing_board,y+j,x+i,' ');
                            }
                    }
                break;
        }
        for(int i = 1 ; i < 96; i+=24)
            {   
                move(1,i);
                for(int y = 1; y < 5; y++)
                    for(int x = 0;x < 11;x++)
                    {
                        mvwaddch(playing_board,y,x+i,' ');
                    }
            }
    }
    wattroff(playing_board,COLOR_PAIR(3));

    refresh();
    wrefresh(playing_board);
}

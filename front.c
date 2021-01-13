#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#define b_b 88
void draw_board();
void main_loop();
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
void main_loop()
{
    WINDOW *coords_input = newwin(4,21,47,10);
    WINDOW *From = newwin(1,3,48,19);
    WINDOW *To = newwin(1,3,49,20);

    box(coords_input,0,0);
    char from[2];
    char to[2];
    int i = 0;
    bool game_over = false;

    box(coords_input,0,0);
    mvwprintw(coords_input,1,1, "Ruch z: ");
    mvwprintw(coords_input,2,1, "Ruch na: ");
    wrefresh(coords_input);

    while(!game_over)
    {   
        box(coords_input,0,0);
        if(i % 2 == 0)
            mvwprintw(coords_input,0,4, "Ruch-bialego");
        else
            mvwprintw(coords_input,0,4, "Ruch-czarnego");
        wrefresh(coords_input);

        wscanw(From,"%s",from);
        move(49,20);
        wscanw(To,"%s",to);
        //funkcja konwertująca
        wclear(From);
        wclear(To);
        i++;
    }
}
void draw_coordinates(WINDOW *board)
{
    init_pair(3, COLOR_WHITE, 239);
    char coord_arts[16][3][4] = {

        {//8
         {' ', '_', ' ', ' '},
         {'(', '_', ')', ' '},
         {'(', '_', ')', ' '}},
        {//7
         {'_', '_', ' ', ' '},
         {' ', '/', ' ', ' '},
         {'/', ' ', ' ', ' '}},
        {//6
         {' ', ' ', ' ', ' '},
         {' ', '/', ' ', ' '},
         {'(', '_', ')', ' '}},
        {//5
         {' ', '_', ' ', ' '},
         {'|', '_', ' ', ' '},
         {' ', '_', ')', ' '}},
        {//4
         {' ', ' ', '.', ' '},
         {' ', '/', '|', ' '},
         {'\'', '-', '|', ' '}},
        {//3
         {'_', ' ', ' ', ' '},
         {'_', ')', ' ', ' '},
         {'_', ')', ' ', ' '}},
        {//2
         {'_', ' ', ' ', ' '},
         {' ', ')', ' ', ' '},
         {'/', '_', ' ', ' '}},
        {//1
         {' ', '.', ' ', ' '},
         {'/', '|', ' ', ' '},
         {' ', '|', ' ', ' '}},
        {//A
         {' ', ' ', ' ', ' '},
         {' ', '/', '\\', ' '},
         {'/', '-', '-', '\\'}},
        {//B
         {' ', '_', ' ', ' '},
         {'|', '_', ')', ' '},
         {'|', '_', ')', ' '}},
        {//C
         {' ', '_', ' ', ' '},
         {'/', ' ', ' ', ' '},
         {'\\', '_', ' ', ' '}},
        {//D
         {' ', '_', ' ', ' '},
         {'|', ' ', '\\', ' '},
         {'|', '_', '/', ' '}},
        {//E
         {' ', '_', '_', ' '},
         {'|', '_', ' ', ' '},
         {'|', '_', '_', ' '}},
        {//F
         {' ', '_', '_', ' '},
         {'|', '_', ' ', ' '},
         {'|', ' ', ' ', ' '}},
        {//G
         {' ', '_', ' ', ' '},
         {'/', '_', ' ', ' '},
         {'\\', '_', '|', ' '}},
        {//H
         {' ', ' ', ' ', ' '},
         {'|', '_', '|', ' '},
         {'|', ' ', '|', ' '}}};
    attron(COLOR_PAIR(1));
    for (int k = 0; k < 8; k++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                mvaddch(i + (5 * k) + 6, j + 3, coord_arts[k][i][j]);
            }
        }
    }
    for (int k = 8; k < 16; k++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                mvaddch(i + 1, j - 82 + (12 * k), coord_arts[k][i][j]);
            }
        }
    }
    attroff(COLOR_PAIR(1));
}
//funkcja sprawdza kolor pola na ktorym ma byc wyrysowana figura
bool field_color(int x, int y)
{   //jesli szare zwraca true, jesli czerwone zwraca false
    if(x % 2 == 0 && y % 2 == 0)
        return true;
    else if(x % 2 == 0 && y % 2 != 0)
        return false;
    else if(x % 2 != 0 && y % 2 == 0)
        return false;
    else if(x % 2 != 0 && y % 2 != 0)
        return true;
}
void draw_pieces(WINDOW *board)
{
    //stworzyć funkcję zwracającą kolor czcionki i funkcję zwracającą kolor tła
    int piece_color = COLOR_BLACK;
    int background_color = b_b;
    init_pair(4, piece_color, background_color);//czerwony
    init_pair(6, COLOR_BLACK, 239);//szary
    int x = 0; //0-7 =
    int y = 7;

    //dopasować kolejność figur względem numeracji w strukturze
    char pieces[6][4][11] = {
        {//wieza
         {' ', '[', '`', '\'', '`', '\'', '`', '\'', '`', ']', ' '},
         {' ', ' ', '|', '+', '+', '+', '+', '+', '|', ' ', ' '},
         {' ', ' ', '|', '+', '+', '+', '+', '+', '|', ' ', ' '},
         {' ', ' ', '|', '+', '+', '+', '+', '+', '|', ' ', ' '}},
        {//pionek
         {' ', ' ', ' ', '(', ' ', ' ', ' ', ')', ' ', ' ', ' '},
         {' ', ' ', ' ', ')', ')', '|', '(', '(', ' ', ' ', ' '},
         {' ', ' ', '(', ' ', ' ', ' ', ' ', ' ', ')', ' ', ' '},
         {' ', '[', '|', '|', '|', '|', '|', '|', '|', ']', ' '}},
        {//kon
         {' ', ' ', ' ', '\\', '`', '~', '\'', '/', ' ', ' ', ' '},
         {' ', ' ', ' ', '(', 'o', ' ', 'o', ')', ' ', ' ', ' '},
         {' ', ' ', ' ', ' ', '\\', ' ', '/', '\\', ' ', ' ', ' '},
         {' ', ' ', ' ', ' ', ' ', '"', ' ', ' ', ' ', ' ', ' '}},
        {//krol
         {' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' '},
         {' ', ' ', ' ', '/', '\\', '^', '/', '\\', ' ', ' ', ' '},
         {' ', ' ', ' ', '(', '-', '_', '-', ')', ' ', ' ', ' '},
         {' ', ' ', ' ', ' ', '(', '_', ')', ' ', ' ', ' ', ' '}},
        {//goniec
         {' ', ' ', ' ', '/', ' ', '+', ' ', '\\', ' ', ' ', ' '},
         {' ', ' ', ' ', '\\', ' ', ' ', ' ', '/', ' ', ' ', ' '},
         {' ', ' ', ' ', '(', 'o', ' ', 'o', ')', ' ', ' ', ' '},
         {' ', ' ', ' ', ' ', '(', '_', ')', ' ', ' ', ' ', ' '}},
        {//hetman
         {' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' ', ' ', ' '},
         {' ', ' ', ' ', '/', '\\', '*', '/', '\\', ' ', ' ', ' '},
         {' ', ' ', '/', '(', 'o', ' ', 'o', ')', '\\', ' ', ' '},
         {' ', ' ', ' ', ' ', '(', '_', ')', ' ', ' ', ' ', ' '}}};
    attron(A_BOLD);
    for (int k = 0; k < 6; k++)
    {
        y = k;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 11; j++)
            {
                //move(i+(x*5),j+(y*12));
                if(field_color(x,y))//true szary, false czerwony
                    mvwaddch(board, i + (x * 5) + 1, j + (y * 12) + 1, pieces[k][i][j] | COLOR_PAIR(6));
                else
                    mvwaddch(board, i + (x * 5) + 1, j + (y * 12) + 1, pieces[k][i][j] | COLOR_PAIR(4));
            }
    }
    attroff(A_BOLD);
}

void draw_board()
{
    start_color();
    char board[9][9];
    WINDOW *playing_board = newwin(41, 97, 5, 10);

    // RYSOWANIE PLANSZY

    init_pair(1, COLOR_YELLOW, COLOR_BLACK); // linie kolor
    init_pair(2, COLOR_WHITE, b_b);          // background kolor (czerwony)
    init_pair(3, COLOR_WHITE, 239);          //kolor szary

    wattron(playing_board, COLOR_PAIR(1));
    box(playing_board, 0, 0);
    for (int y = 5; y < 48; y += 5) // podzial poziomy
    {
        mvwhline(playing_board, y, 1, 0, 95);
    }
    for (int x = 12; x < 96; x += 12) // podzial pionowy
    {
        mvwvline(playing_board, 0, x, 0, 40);
    }
    for (int x = 12; x < 96; x += 12)
        mvwhline(playing_board, 40, x, ACS_BTEE, 1); // laczenia dolne
    for (int x = 12; x < 96; x += 12)
        mvwhline(playing_board, 0, x, ACS_TTEE, 1); // laczenia gorne
    for (int y = 5; y < 40; y += 5)
        mvwvline(playing_board, y, 96, ACS_RTEE, 1); // laczenia prawe
    for (int y = 5; y < 40; y += 5)
        mvwvline(playing_board, y, 0, ACS_LTEE, 1); // laczenia lewe
    for (int i = 12; i < 96; i += 12)
        for (int j = 5; j < 40; j += 5) // laczenia wewnetrzne
            mvwaddch(playing_board, j, i, ACS_PLUS);
    wattroff(playing_board, COLOR_PAIR(1));

    int temp;
    for (int j = 1; j < 40; j += 5)
    {
        switch (j % 2)
        {
        case 0:
            for (int i = 13; i < 96; i += 24) //kolorowanie komorek w wierszach 1,3,5,7
            {
                move(j, i);
                for (int y = 0; y < 4; y++)
                    for (int x = 0; x < 11; x++)
                    {
                        mvwaddch(playing_board, y + j, x + i, ' ' | COLOR_PAIR(3));
                    }
            }
            for (int i = 1; i < 96; i += 24) 
            {
                move(j, i);
                for (int y = 0; y < 4; y++)
                    for (int x = 0; x < 11; x++)
                    {
                        mvwaddch(playing_board, y + j, x + i, ' ' | COLOR_PAIR(2));
                    }
            }
            break;
        case 1:
            for (int i = 1; i < 96; i += 24) // kolorowanie komorek w wierszach 2,4,6,8
            {
                move(j, i);
                for (int y = 0; y < 4; y++)
                    for (int x = 0; x < 11; x++)
                    {
                        mvwaddch(playing_board, y + j, x + i, ' ' | COLOR_PAIR(3));
                    }
            }
            for (int i = 13; i < 96; i += 24) 
            {
                move(j, i);
                for (int y = 0; y < 4; y++)
                    for (int x = 0; x < 11; x++)
                    {
                        mvwaddch(playing_board, y + j, x + i, ' ' | COLOR_PAIR(2));
                    }
            }
            break;
        }
    }
    /* test for displaying chess piece on board
    wattron(playing_board,COLOR_PAIR(1));
    
    char piece[3][4] ={
                    {' ','(',')',' '},
                    {' ',')','(',' '},
                    {'/','_','_','\\'}
    };
    
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++)
        {
            move(i+9,j+85);
            mvwaddch(playing_board, i+9,j+85,piece[i][j]);
        }
    wattroff(playing_board,COLOR_PAIR(1));*/
    draw_coordinates(playing_board);
    draw_pieces(playing_board);
    refresh();
    wrefresh(playing_board);
}

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// struktura pionka szachowego
typedef struct cp {
    int X; // przechowuje wiersz
    int Y; // przechowuje kolumne
    int Color; // przechowuje kolor
    int Type; // przechowuje typ
    bool (*moveFunctionPointer)(int color, int xA, int yA, int xB, int yB); // przechowuje funkcje ruchu pionka
} ChessPiece;

// tablica zawierajaca wskazniki na pionki znajdujace sie danej pozycji planszy
ChessPiece *Board[9][9];

// allokuje pamiec na pionek i przypisuje mu wartosci poczatkowe
ChessPiece *initChessPiece(int xA, int yA, int color, int type, bool (*piecemove)());

// zwraca pionek znajdujacy sie na danym polu
ChessPiece getChessPiece(int xA, int yA);

// usuwa bionek znajdujacy sie na danym polu
void removeChessPiece(int xA, int yA);

// ustawia pionek na dane pole
void setChessPiece(ChessPiece piece, int xB, int yB);

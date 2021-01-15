#include "structure.h"
#include "gamerules.h"

// tablica zawierajaca wskazniki na pionki znajdujace sie danej pozycji planszy
ChessPiece *Board[9][9];

ChessPiece getChessPiece(int xA, int yA) {
    ChessPiece *pom = Board[xA][yA];
    ChessPiece result = *pom;
    return result;
}

void removeChessPiece(int xA, int yA) {
    free(Board[xA][yA]);
    ChessPiece *pom = initChessPiece(xA, yA, 0, 0, &emptyTileMove);
    Board[xA][yA] = pom;
}

ChessPiece *initChessPiece(int xA, int yA, int color, int type,bool (*moveFunctionPointer)(int color, int xA, int yA, int xB, int yB)) {
    ChessPiece *result = (ChessPiece *) malloc(sizeof(ChessPiece));
    result->X = xA;
    result->Y = yA;
    result->color = color;
    result->type = type;
    result->moveFunctionPointer = moveFunctionPointer;
    return result;
}

void setChessPiece(ChessPiece piece, int xB, int yB) {
    ChessPiece *pom = initChessPiece(xB, yB, piece.color, piece.type, piece.moveFunctionPointer);
    Board[xB][yB] = pom;
}

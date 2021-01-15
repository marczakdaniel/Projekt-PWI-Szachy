#include "structure.h"

ChessPiece getChessPiece(int xA, int yA) {
    ChessPiece *pom = Board[xA][yA];
    ChessPiece result = *pom;
    return result;
}

ChessPiece *initChessPiece(int xA, int yA, int color, int type, bool (*piecemove)()) {
    ChessPiece *result = (ChessPiece *) malloc(sizeof(ChessPiece));
    result->X = xA;
    result->Y = yA;
    result->Color = color;
    result->Type = type;
    result->moveFunctionPointer = piecemove;
    return result;
}

void removeChessPiece(int xA, int yA) {
    free(Board[xA][yA]);
    ChessPiece *pom = initChessPiece(xA, yA, 0, 0, /*miejsce na funcje */); // trzeba dodac funkcje
    Board[xA][yA] = pom;
}

void setChessPiece(ChessPiece piece, int xB, int yB) {
    ChessPiece *pom = initChessPiece(xB, yB, piece.Color, piece.Type, piece.moveFunctionPointer);
    Board[xB][yB] = pom;
}

#include <stdbool.h>
#include <stdlib.h>
#include "structure.h"
#include "gamerules.h"

void gameInit() {
	ChessPiece newChessPiece;
	//------WIEŻE---------
	newChessPiece.color = 1;
	newChessPiece.type = 2;
	newChessPiece.moveFunctionPointer = &checkRookMove;
	setChessPiece(newChessPiece, 0, 0);
	setChessPiece(newChessPiece, 7, 0);
	
	newChessPiece.color = 2;
	setChessPiece(newChessPiece, 0, 7);
	setChessPiece(newChessPiece, 7, 7);
	//--------KONIE---------
	newChessPiece.type = 3;
	newChessPiece.color = 1;
	newChessPiece.moveFunctionPointer = &checkKnightMove;
	setChessPiece(newChessPiece, 1, 0);
	setChessPiece(newChessPiece, 6, 0);
	
	newChessPiece.color = 2;
	setChessPiece(newChessPiece, 1, 7);
	setChessPiece(newChessPiece, 6, 7);
	
	//--------GOŃCE-----------
	newChessPiece.color = 1;
	newChessPiece.type = 4;
	newChessPiece.moveFunctionPointer = &checkBishopMove;
	setChessPiece(newChessPiece, 2, 0);
	setChessPiece(newChessPiece, 5, 0);
	
	newChessPiece.color = 2;
	setChessPiece(newChessPiece, 2, 7);
	setChessPiece(newChessPiece, 5, 7);
	
	//--------KRÓLOWE----------
	newChessPiece.color = 1;
	newChessPiece.type = 5;
	newChessPiece.moveFunctionPointer = &checkQueenMove;
	setChessPiece(newChessPiece, 3, 0);
	
	newChessPiece.color = 2;
	setChessPiece(newChessPiece, 3, 7);
	
	//--------KRÓLOWIE----------
	
	newChessPiece.color = 1;
	newChessPiece.type = 6;
	newChessPiece.moveFunctionPointer = &checkKingMove;
	setChessPiece(newChessPiece, 4, 0);
	newChessPiece.color = 2;
	setChessPiece(newChessPiece, 4, 7);
	
	//-------PIONKI-----------
	
	newChessPiece.color = 1;
	newChessPiece.type = 1;
	newChessPiece.moveFunctionPointer = &checkPawnsMove;
	for(int i = 0 ; i < 8; i++) {
		setChessPiece(newChessPiece, i, 1);
	}
	newChessPiece.color = 2;
	for(int i = 0 ; i < 8; i++) {
		setChessPiece(newChessPiece, i, 6);
	}
	//-----PUSTE POLA--------
	
	newChessPiece.color = 0;
	newChessPiece.type = 0;
	newChessPiece.moveFunctionPointer = &emptyTileMove;
	for(int i = 0 ; i < 8; i++) {
		for(int j = 2; j < 6; j++)
		setChessPiece(newChessPiece, i, j);
	}
	
	return;
}

bool performMove(int xA, int yA, int xB, int yB) {
	//nie można wykonać ruchu w miejscu
	if(xA == xB && yA == yB) return false;
	ChessPiece chessPiece = getChessPiece(xA, yA);
	if(!chessPiece.moveFunctionPointer(chessPiece.color, xA, yA, xB, yB)) {
		return false;
	}
	if(getChessPiece(xA, yA).color == getChessPiece(xB, yB).color)
			return false;
	removeChessPiece(xA, yA); removeChessPiece(xB, yB);
	setChessPiece(chessPiece, xB, yB);
	return true;
}

//Podejście "branchless" bo ifowanie jest mniej czytelne
bool emptyTileMove(int color, int xA, int yA, int xB, int yB) {
	return false;
}

bool checkPawnsMove(int color, int xA, int yA, int xB, int yB) {
	return false;
}

//goniec
//TODO sprawdzenie czy pola pomiędzy A i B są puste
bool checkBishopMove(int color, int xA, int yA, int xB, int yB) {
	//sprawdzenie czy ruch jest po skosie
	if(xA - yA != xB - yB) return false;
	return false;
}

//koń
bool checkKnightMove(int color, int xA, int yA, int xB, int yB) {
	//koń może się poruszyć o -/+ 1/2 pola w pionie i -/+ 2/1 pola w poziomie
	//suma musi być równa 3 i każdy z dystansów minimum 1
	if(abs(xA-xB) + abs(yA-yB) == 3 && abs(xA-xB) > 0 && abs(yA- yB) > 0) 
		return true;
	return false;
}

//wieża
bool checkRookMove(int color, int xA, int yA, int xB, int yB) {
	//wieża przesuwa się wzdłuz jednej osi
	if(xA != xB && yA != yB) return false;
	
	if(xA == yA) {
		for(int i = min(yB, yA) + 1; i < max(yB, yA); i++) {
			//getChessPiece jeszcze nie gotowy
			if(getChessPiece(xA, i).type != 0) return false;
		}
		return true;
	}
	//else
	for(int i = min(xB, xA) + 1; i < max(xB, xA); i++) {
		//getChessPiece jeszcze nie gotowy
		if(getChessPiece(i, yA).type != 0) return false;
	}
	return true;
}

bool checkQueenMove(int color, int xA, int yA, int xB, int yB) {
	//można wykorzystać gotowe funkcje dla gońca i wieży
	return false;
}

bool checkKingMove(int color, int xA, int yA, int xB, int yB) {
	return false;
}

int checkWinCondition(int color) {
	return 0;
}

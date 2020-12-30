void gameInit() {
	return;
}

bool performMove(int xA, int yA, int xB, int yB) {
	//nie można wykonać ruchu w miejscu
	if(xA == xB && yA == yB) return false;
	ChessPiece chessPiece = getChessPiece(xA, yA);
	if(!chessPiece.moveFunctionPointer(int color, int xA, int yA, int xB, int yB)) {
		return false;
	}
	removeChessPiece(xA, yA); removeChessPiece(yA, yB);
	setChessPiece(chessPiece, xA, yA);
	return true;
}


bool emptyTileMove(int color, int xA, int yA, int xB, int yB) {
	return false;
}

bool checkPawnsMove(int color, int xA, int yA, int xB, int yB) {
	return false;
}

bool checkBishopMove(int color, int xA, int yA, int xB, int yB) {
	return false;
}

bool checkKnightMove(int color, int xA, int yA, int xB, int yB) {
	return false;
}

bool checkRookMove(int color, int xA, int yA, int xB, int yB) {
	return false;
}

bool checkQueenMove(int color, int xA, int yA, int xB, int yB) {
	return false;
}

bool checkKingMove(int color, int xA, int yA, int xB, int yB) {
	return false;
}

int checkWinCondition(int color) {
	return 0;
}

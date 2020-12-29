//Poniższe funkcje sprawdzają czy dany pionek może się poruszyć z pola A na pole B
//Jeśli może to funkcja zwraca true i wykonuje ruch (performMove()) który aktualizuje stan planszy
//w przeciwnym przypadku zwracany jest false
bool checkPawnsMove(int color, int xA, int yA, int xB, int yB);
bool checkBishopMove(int color, int xA, int yA, int xB, int yB);
bool checkKnightMove(int color, int xA, int yA, int xB, int yB);
bool checkRookMove(int color, int xA, int yA, int xB, int yB);
bool checkQueenMove(int color, int xA, int yA, int xB, int yB);
bool checkKingMove(int color, int xA, int yA, int xB, int yB);

void performMove(int xA, int yA, int xB, int yB);

//Funkcja sprawdza planszę i zwraca informacje o ewentualnym końcu gry
// 0 - Nikt nie wygrał
// 1 - Wygrał gracz który jest identyfikowany przez zmienną 'color'
// 2 - Pat aka remis
int checkWinCondition(int color);

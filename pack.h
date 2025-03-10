#include <iostream>
using namespace std;

class Toe{
	public:
	int p1[5],p2[4];
	char board[3][3];
	Toe();
	void startGame();
	void placeMark(int , char);
	bool checkWin(char);
};
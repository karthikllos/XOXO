#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
#include "pack.h"
int main(){
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int c;
    cout << "1.Player vs Player\n"<< "2.Player vs Computer\n" << "3.Computer vs Computer" << endl;
    cin >> c;
    if(c==1){
        Toe G;
        G.startGame();
        while(true){
            cout << "Player 1: ";
            cin >> c;
            G.placeMark(c, 'X');
            if(G.checkWin('X')){
                break;
            }
            cout << "Player 2: ";
            cin >> c;
            G.placeMark(c, 'O');
            if(G.checkWin('O')){
                break;
            }
        }
    } else if(c==2){
        Toe G;
        G.startGame();
        while(true){
            cout << "Player 1: ";
            cin >> c;
            G.placeMark(c, 'X');
            if(G.checkWin('X')){
                break;
            }
            cout << "Computer's Move: "<<endl;
            srand(time(0));
            int r;
            do {
                srand(time(0));
                r = rand() % 9 + 1;
            } while(G.board[(r - 1) / 3][(r - 1) % 3] == 'X' || G.board[(r - 1) / 3][(r - 1) % 3] == 'O');
            G.placeMark(r, 'O');
            if(G.checkWin('O')){
                break;
            }
        }
    } else if(c==3){
        Toe G;
        G.startGame();
        while(true){
            int i=0;
            cout << "Computer 1 Move: "<<endl;
            srand(time(0));
            int r ;
            do {
                srand(time(0));
                r = rand() % 9 + 1;
            } while(G.board[(r - 1) / 3][(r - 1) % 3] == 'X' || G.board[(r - 1) / 3][(r - 1) % 3] == 'O');
            G.p1[i] = r;
            G.placeMark(r, 'O');
            if(G.checkWin('O')){
                break;
            }
            cout << "Computer 2 Move: "<<endl;
            srand(time(0)+1);
            int r1 ;
            do {
                srand(time(0));
                r1 = rand() % 9 + 1;
            } while(G.board[(r1 - 1) / 3][(r1 - 1) % 3] == 'X' || G.board[(r1 - 1) / 3][(r1 - 1) % 3] == 'O');
            G.p2[i] = r1;
            G.placeMark(r1, 'X');
            if(G.checkWin('X')){
                break;
            }
            i++;
        }
    }
    return 0;
}
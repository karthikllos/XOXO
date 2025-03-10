#include "pack.h"
Toe::Toe(){
    for(int i = 0; i < 3; i++){
        p1[i]=0;
        p2[i]=0;
        for(int j = 0; j < 3; j++){
            board[i][j] = '0' + (i * 3) + j + 1;
        }
    }
}
void Toe::startGame(){
    int choice, player = 1, i, j;
    char mark;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void Toe::placeMark(int choice, char mark){
    int row, col;
    if(choice >= 1 && choice <= 9){
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;
        if(board[row][col] == 'X' || board[row][col] == 'O'){
            cout << "Invalid Move. Try again." << endl;
            return;
        }
        board[row][col] = mark;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }else{
        cout << "Invalid Choice. Try again." << endl;
    }
}
bool Toe::checkWin(char mark){
    for(int i = 0; i < 3; i++){
        if((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
        (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)){
            cout << "Player " << mark << " wins!" << endl;
            return true;
        }
    }
    if((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
    (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)){
        cout << "Player " << mark << " wins!" << endl;
        return true;
    }
    int d;
    for(int i=0; i<3; i++){
        for(int j=0; j<3;j++){
            if(board[i][j] == 'X' || board[i][j] == 'O'){
                d=1;
            } else {d=0; return false;}
        }
    }
    if(d==1) {
        cout << "It's a draw!" << endl;
        return true;
    }
}
//
// Created by Nour on 2024-12-05.
//

#include "Board_PTTT.h"

Board_PTTT::Board_PTTT(){
    this -> rows = 3;
    this -> columns = 5
    this -> n_moves = n_moves;
    this -> board = new char*[3];
    board[0] = new char[1];
    board[1] = new char[3];
    board[2] = new char[5];
}

Board_PTTT::~Board_PTTT() {
    for (int i = 0; i < 3; i++){
        delete[] this->board[i];
    }
    delete[] this->board;
}

bool Board_PTTT::update_board(int x, int y, char symbol) {

    if(x < 0 || y < 0){
        return false;
    }
    if(x != 2 && y == 0 ){
        return false;
    }
    if(x == 0 && y == 1 ){
        return false;
    }
    if(x == 4 && y == 1 ){
        return false;
    }
    if(x >= 5 || y >= 3){
        return false;
    }
    if( board[y][x] != 0) {
        return false;
    }
    if( board[y][x] == 0) {
        board[y][x] = symbol;
        this -> n_moves++;
        return true;

    }
}
void Board_PTTT::display_board() {

    cout << setw(9) << board[0][2] << endl;

    cout << setw(6) << board[1][1]
         << setw(3) << board[1][2]
         << setw(3) << board[1][3] << endl;

    for (int j = 0; j < 5; j++) {
        cout << setw(3) << board[2][j];
    }
    cout << endl;
}
bool Board_PTTT::is_win() {
    T player;
    // Check middle vertical
    if (board[0][2] != 0 &&
        board[0][2] == board[1][2] &&
        board[1][2] == board[2][2]) {
        return true;
    }
    // Check left diagonal
    if (board[0][2] != 0 &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]){
        return true;
    }
    // Check right diagonal
    if (board[0][2] != 0 &&
        board[0][2] == board[1][3] &&
        board[1][3] == board[2][4]){
        return true;
    }
    // Check middle horizontal
    if (board[1][1] != 0 &&
        board[1][1] == board[1][2] &&
        board[1][2] == board[1][3]){
        return true;
    }
    // Check middle bottom horizontal
    if (board[2][1] != 0 &&
        board[2][1] == board[2][2] &&
        board[2][2] == board[2][3]){
        return true;
    }
    // Check left bottom horizontal
    if (board[2][0] != 0 &&
        board[2][0] == board[2][1] &&
        board[2][1] == board[2][2]){
        return true;
    }
    // Check right bottom horizontal
    if (board[2][2] != 0 &&
        board[2][2] == board[2][3] &&
        board[2][3] == board[2][4]){
        return true;
    }
}
bool Board_PTTT::is_draw() {
   return n_moves >= 7 && !is_win();
}
bool Board_PTTT::game_is_over() {
    return is_win() || is_draw();
}
}
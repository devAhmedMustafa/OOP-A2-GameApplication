//
// Created by Nour on 2024-12-05.
//

#include "PTTT_Board.h"
#include <iostream>
#include <iomanip>

PTTT_Board::PTTT_Board(){
    this -> rows = 3;
    this -> columns = 5;
    this -> n_moves = n_moves;
    this -> board = new char*[3];
    board[0] = new char[1](0);
    board[1] = new char[3](0);
    board[2] = new char[5](0);
}

PTTT_Board::~PTTT_Board() {
    for (int i = 0; i < 3; i++){
        delete[] this->board[i];
    }
    delete[] this->board;
}

bool PTTT_Board::update_board(int x, int y, char symbol) {

    if(x < 0 || y < 0){
        return false;
    }
    if(y == 0 && x > 0 ){
        return false;
    }

    if(y == 1 && x > 2){
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

    return false;
}
void PTTT_Board::display_board() {

    cout << setw(9) << (board[0][0] == 0? '-':board[0][0]) << endl;

    cout << setw(6) << (board[1][0] == 0? '-':board[1][0])
         << setw(3) << (board[1][1] == 0? '-':board[1][1])
         << setw(3) << (board[1][2] == 0? '-':board[1][2]) << endl;

    for (int j = 0; j < 5; j++) {
        cout << setw(3) << (board[2][j] == 0? '-':board[2][j]);
    }
    cout << endl;
}

bool PTTT_Board::is_win() {

    // Check middle vertical
    if (board[0][0] != 0 &&
        board[0][0] == board[1][2] &&
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

    return false;
}
bool PTTT_Board::is_draw() {
   return n_moves >= 9 && !is_win();
}
bool PTTT_Board::game_is_over() {
    return is_win() || is_draw();
}

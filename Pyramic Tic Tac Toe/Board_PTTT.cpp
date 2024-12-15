//
// Created by Nour on 2024-12-05.
//

#include "Board_PTTT.h"

Board_PTTT::Board_PTTT(){
    this -> rows = 3;
    this -> columns = 5;
    this -> board = new char*[3];
    board[0] = new char[1];
    board[1] = new char[3];
    board[2] = new char[5];
}
bool Board_PTTT::update_board(int x, int y, char symbol) {

    if(x < 0 || y < 0){
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
        return true;
    }
}
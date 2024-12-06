//
// Created by am180 on 12/5/2024.
//

#include "Board_Four_In_Row.h"

Board_Four_In_Row::Board_Four_In_Row() {
    this->rows = 6;
    this->columns = 7;
    this->board = new char*[6];

    for (int i = 0; i < 6; i++){
        this->board[i] = new char[7];
    }
}

bool Board_Four_In_Row::place(int x, char symbol) {
    if (x < 0 || x >= this->columns){
        return false;
    }

    if (this->filled[x] < 0){
        return false;
    }

    int row = this->filled[x];
    this->board[row][x] = symbol;

    return false;
}
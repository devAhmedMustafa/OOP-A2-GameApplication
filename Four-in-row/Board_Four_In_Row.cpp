//
// Created by am180 on 12/5/2024.
//

#include "Board_Four_In_Row.h"
#include "../Utils/GameTheory.h"
#include <iomanip>

Board_Four_In_Row::Board_Four_In_Row() {
    this->rows = 6;
    this->columns = 7;
    this->board = new char*[6];

    for (int i = 0; i < 6; i++){
        this->board[i] = new char[7];
    }
}

void Board_Four_In_Row::display_board() {
    cout << "  ";
    for (int j = 0; j < 7; j++) {
        cout << setw(3) << j + 1;
    }
    cout << endl;


    for (int i = 0; i < 6; i++) {
        cout << setw(2) << i + 1;
        for (int j = 0; j < 7; j++) {
            cout << setw(3) << this->board[i][j];
        }
        cout << endl;
    }
}

bool Board_Four_In_Row::is_win() {
    vector<vector<int>> hKernel = {{1,1,1,1}};
    vector<vector<int>> vKernel = {{1},{1},{1},{1}};
    vector<vector<int>> dKernel = {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };
    vector<vector<int>> d2Kernel = {
        {0,0,0,1},
        {0,0,1,0},
        {0,1,0,0},
        {1,0,0,0}
    };

    auto mapping = map<char, int>{{'X', 1}, {'O', -1}};
    int** normalizedBoard = GameTheory::normalizeBoard(this->board, this->rows, this->columns, mapping);

    int winner = GameTheory::checkWinner(normalizedBoard, {hKernel, vKernel, dKernel, d2Kernel}, this->rows, this->columns, 4);

    if (winner == 1){
        cout << "Player 1 wins!" << endl;
    } else if (winner == -1){
        cout << "Player 2 wins!" << endl;
    }

    return winner;
}

bool Board_Four_In_Row::game_is_over() {
    return false;
}

bool Board_Four_In_Row::is_draw() {
    return false;
}

bool Board_Four_In_Row::update_board(int x, int y, char symbol) {
    if (x < 0 || x >= this->columns){
        return false;
    }

    if (this->filled[x] < 0){
        return false;
    }

    this->board[this->filled[x]][x] = symbol;
    this->filled[x]--;

    return false;
}
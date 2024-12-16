//
// Created by Ahmed Mustafa on 12/16/2024.
//

#include "ITTT_Board.h"

#include <iostream>
#include <iomanip>

#include "../Tic-Tac-Toe/TTT.h"
#include "../Utils/GameTheory.h"

ITTT_Board::ITTT_Board() {
    this->rows = 3;
    this->columns = 3;
    this->n_moves = 0;
    this->board = new char *[3];

    for (int i = 0; i < 3; i++) {
        this->board[i] = new char[3](0);
    }
}

ITTT_Board::~ITTT_Board() {
    for (int i = 0; i < 3; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

bool ITTT_Board::update_board(int x, int y, char symbol) {

    if (x < 0 || y < 0) {
        return false;
    }

    if (x >= 3 || y >= 3) {
        return false;
    }

    if (board[y][x] != 0) {
        return false;
    }

    if (board[y][x] == 0) {
        board[y][x] = symbol;
        this->n_moves++;
        last_symbol = symbol;
        return true;
    }

    return false;
}

void ITTT_Board::display_board() {

    cout << "  ";
    for (int i = 0; i < 3; i++) {
        cout << setw(3) << i+1;
    }
    cout << endl;

    for (int i = 0; i < 3; i++) {
        cout << setw(2) << i+1;
        for (int j = 0; j < 3; j++) {
            cout << setw(3) << board[i][j];
        }
        cout << endl;
    }
}

bool ITTT_Board::is_draw() {
    return this->n_moves == 9;
}

bool ITTT_Board::game_is_over() {
    return this->is_draw() || this->is_win();
}

bool ITTT_Board::is_win() {

    vector<vector<int>> hKernel = {{1,1,1}};
    vector<vector<int>> vKernel = {{1},{1},{1}};
    vector<vector<int>> dKernel = {{1,0,0},{0,1,0},{0,0,1}};
    vector<vector<int>> d2Kernel = {{0,0,1},{0,1,0},{1,0,0}};

    map<char, int> mapping = {{'X', 1}, {'O', -1}};
    auto normalized_board = GameTheory::normalizeBoard(this->board, 3, 3, mapping);

    int win = GameTheory::checkWinner(normalized_board, {hKernel, vKernel, dKernel, d2Kernel}, 3, 3, 3);

    if (last_symbol == 'X' && win == -1) {
        return true;
    }

    if (last_symbol == 'O' && win == 1) {
        return true;
    }

    return false;

}



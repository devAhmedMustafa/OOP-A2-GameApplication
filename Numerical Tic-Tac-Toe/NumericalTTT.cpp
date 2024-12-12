//
// Created by Ahmed Mustafa on 12/12/2024.
//

#include "NumericalTTT.h"
#include <iomanip>
#include <iostream>

#include "../Utils/GameTheory.h"

NumericalTTT::NumericalTTT() {
    this->rows = 3;
    this->columns = 3;
    this->board = new int*[3];

    for (int i = 0; i < 3; i++){
        this->board[i] = new int[3](0);
    }
}

bool NumericalTTT::update_board(int x, int y, int symbol) {
    if (x < 0 || x >= 3 || y < 0 || y >= 3 || this->board[x][y] != 0){
        return false;
    }

    this->board[x][y] = symbol;
    this->n_moves++;
    return true;
}

void NumericalTTT::display_board() {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << setw(3) << this->board[i][j];
        }
        cout << endl;
    }
}

bool NumericalTTT::is_draw() {
    return this->n_moves == 9;
}

bool NumericalTTT::game_is_over() {
    return this->is_win() || this->is_draw();
}

bool NumericalTTT::is_win() {

    vector<vector<int>> kernelHorizontal = {{1, 1, 1}};
    vector<vector<int>> kernelVertical = {{1}, {1}, {1}};
    vector<vector<int>> kernelDiagonal1 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    vector<vector<int>> kernelDiagonal2 = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}};
    auto kernels = {kernelHorizontal, kernelVertical, kernelDiagonal1, kernelDiagonal2};

    return GameTheory::checkWinner(this->board, kernels, 3, 3, 15);
}

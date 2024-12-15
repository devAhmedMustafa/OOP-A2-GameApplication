//
// Created by Ahmed Mustafa on 12/14/2024.
//

#include "SUS_Board.h"

#include <iomanip>
#include <iostream>

#include "../Utils/GameTheory.h"

using namespace std;

SUS_Board::SUS_Board() {
    board = new char*[3];
    for (int i = 0; i < 3; i++) {
        board[i] = new char[3](0);
    }
}

SUS_Board::~SUS_Board() {
    for (int i = 0; i < 3; i++) {
        delete[] board[i];
    }
    delete[] board;
}


void SUS_Board::display_board() {
    cout << " ";
    for (int i = 0; i < 3; i++) {
        cout << setw(3) << i + 1;
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << setw(2) << i + 1;
        for (int j = 0; j < 3; j++) {
            cout << setw(3) << board[i][j];
        }
        cout << endl;
    }
}

bool SUS_Board::update_board(int x, int y, char symbol) {

    if (x < 0 || x > 2 || y < 0 || y > 2) {
        return false;
    }

    if (board[x][y] == 0) {
        board[x][y] = symbol;
        return true;
    }
    return false;
}

bool SUS_Board::is_win() {

    vector<vector<int>> hKernel = {{1, 2, 1}};
    vector<vector<int>> vKernel = {{1}, {2}, {1}};
    vector<vector<int>> dKernel = {
        {1, 0, 0},
        {0, 2, 0},
        {0, 0, 1}
    };

    vector<vector<int>> diKernel = {
        {0, 0, 1},
        {0, 2, 0},
        {1, 0, 0}
    };

    map<char, int> mapping = {{'S', 1}, {'U', 1}};
    auto normalized_board = GameTheory::normalizeBoard(board, 3, 3, mapping);

    return GameTheory::checkWinner(normalized_board, {hKernel, vKernel, dKernel, diKernel}, 3, 3, 4);

}

bool SUS_Board::is_draw() {
    return n_moves == 9;
}

bool SUS_Board::game_is_over() {
    return is_win() || is_draw();
}


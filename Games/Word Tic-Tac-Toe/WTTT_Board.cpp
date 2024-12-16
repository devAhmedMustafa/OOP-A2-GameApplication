//
// Created by Nour on 2024-12-15.
//

#include "WTTT_Board.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

#include "../Utils/GameTheory.h"

WTTT_Board::WTTT_Board() {
    this->rows = 3;
    this->columns = 3;
    this->n_moves = 0;
    this->board = new char *[3];

    for (int i = 0; i < 3; i++) {
        this->board[i] = new char[3](0);
    }
}

WTTT_Board::~WTTT_Board() {
    for (int i = 0; i < 3; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

bool WTTT_Board::update_board(int x, int y, char symbol) {

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
        return true;
    }

    return false;
}

void WTTT_Board::display_board() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(3) << board[i][j];
        }
        cout << endl;
    }
}

bool WTTT_Board::is_draw() {
    return this->n_moves == 9;
}

bool WTTT_Board::is_win() {

    vector<vector<int>> hKernel = {{1,1,1}};
    vector<vector<int>> vKernel = {{1},{1},{1}};
    vector<vector<int>> dKernel = {{1,0,0},{0,1,0},{0,0,1}};
    vector<vector<int>> d2Kernel = {{0,0,1},{0,1,0},{1,0,0}};

    ifstream file("dict.txt");
    vector<string> words;
    string line;
    while (getline(file, line)) {
        words.push_back(line);
    }

    for (auto & word : words) {

        map<char, int> mapping;
        for (int j = 0; j < word.size(); j++) {
            mapping[word[j]] = 1;
        }

        const auto normalized_board = GameTheory::normalizeBoard(board, 3, 3, mapping);

        if (bool isWin = GameTheory::checkWinner(normalized_board, {hKernel, vKernel, dKernel, d2Kernel}, 3, 3, 3))
            return true;

    }

    return false;

}

bool WTTT_Board::game_is_over() {
    return is_win() || is_draw();
}
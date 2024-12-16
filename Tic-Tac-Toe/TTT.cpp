//
// Created by Ahmed Mustafa on 12/17/2024.
//

#include "TTT.h"
#include <iostream>
#include <iomanip>

using namespace std;

TTT::TTT() {
    board = new char*[3];
    for (int i = 0; i < 3; i++) {
        board[i] = new char[3](0);
    }
}

TTT::TTT(const ITTT_Board& new_board) {
    this->board = new char*[3];
    for (int i = 0; i < 3; i++) {
        this->board[i] = new char[3];
        for (int j = 0; j < 3; j++) {
            this->board[i][j] = new_board.board[i][j];
        }
    }
}

TTT::~TTT() {
    for (int i = 0; i < 3; i++) {
        delete[] board[i];
    }
    delete[] board;
}

bool TTT::update_board(int x, int y, char symbol) {
    if (x < 0 || x >= 3 || y < 0 || y >= 3) {
        return false;
    }

    if (board[y][x] == 0) {
        board[y][x] = symbol;
        n_moves++;
        return true;
    }

    return false;
}

void TTT::display_board() {
    cout << "  ";
    for (int i = 0; i < 3; i++) {
        cout << "  " << i + 1;
    }

    cout << endl;

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << "  " << board[i][j];
        }
        cout << endl;
    }
}

bool TTT::is_draw() {
    return n_moves == 9;
}

bool TTT::is_win() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0) {
            return true;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) {
        return true;
    }

    return false;
}

bool TTT::game_is_over() {
    return is_win() || is_draw();
}

void TTT::flip_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < i; j++) {
            if (board[i][j] == 'X')
                board[i][j] = 'O';
            if (board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}

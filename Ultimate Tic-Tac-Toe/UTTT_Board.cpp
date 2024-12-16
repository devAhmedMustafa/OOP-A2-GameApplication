//
// Created by Ahmed Mustafa on 12/14/2024.
//

#include "UTTT_Board.h"
#include <iostream>
#include <iomanip>

using namespace std;


UTTT_Board::UTTT_Board() {
    board = new char*[3];

    for (int i = 0; i < 3; i++) {
        board[i] = new char[3](0);
    }
}

UTTT_Board::~UTTT_Board() {
    for (int i = 0; i < 3; i++) {
        delete[] board[i];
    }
    delete[] board;
}

void UTTT_Board::display_board() {

    cout << "  ";
    for (int i = 0; i < 9; i++) {
        cout << "  " << i + 1;
    }

    cout << endl;

    for (int i = 0; i < 9; i++) {
        cout << setw(2) << i + 1;
        for (int j = 0; j < 9; j++) {
            int subBoardIndex = (i / 3) * 3 + (j / 3);
            cout << setw(3) << boards[subBoardIndex].board[i % 3][j % 3];
        }
        cout << endl;
    }
}

bool UTTT_Board::update_board(int x, int y, char symbol) {
    if (x < 0 || x >= 9 || y < 0 || y >= 9) {
        return false;
    }

    int subBoardIndex = (y / 3) * 3 + (x / 3);

    if (boards[subBoardIndex].update_board(x % 3, y % 3, symbol)) {
        if (boards[subBoardIndex].is_win()) {
            board[y / 3][x / 3] = symbol;
        }
        return true;
    }

    return false;
}

bool UTTT_Board::is_draw() {
    for (int i = 0; i < 9; i++) {
        if (!boards[i].is_draw()) {
            return false;
        }
    }

    return true;
}

bool UTTT_Board::is_win() {
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

bool UTTT_Board::game_is_over() {
    return is_win() || is_draw();
}

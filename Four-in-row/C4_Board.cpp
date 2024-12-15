//
// Created by am180 on 12/5/2024.
//

#include "C4_Board.h"
#include "../Utils/GameTheory.h"
#include <iomanip>

C4_Board::C4_Board() {
    this->rows = 6;
    this->columns = 7;
    this->board = new char*[6];

    for (int i = 0; i < 6; i++){
        this->board[i] = new char[7];
    }
}

C4_Board::C4_Board(const C4_Board &board) {
    this->rows = board.rows;
    this->columns = board.columns;
    this->n_moves = board.n_moves;
    this->board = new char*[6];

    for (int i = 0; i < 6; i++){
        this->board[i] = new char[7];
        for (int j = 0; j < 7; j++){
            this->board[i][j] = board.board[i][j];
        }
    }

    for (int i = 0; i < 7; i++){
        this->filled[i] = board.filled[i];
    }
}

C4_Board::~C4_Board() {
    for (int i = 0; i < 6; i++){
        delete[] this->board[i];
    }
    delete[] this->board;
}

vector<float> C4_Board::flatten_board() const {
    vector<float> flattened_board;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            if (this->board[i][j] == 'X'){
                flattened_board.push_back(1);
            } else if (this->board[i][j] == 'O'){
                flattened_board.push_back(-1);
            } else {
                flattened_board.push_back(0);
            }
        }
    }

    return flattened_board;
}

void C4_Board::display_board() {
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

bool C4_Board::is_win() {
    vector<vector<int>> hKernel = {{1,1,1,1}};
    vector<vector<int>> vKernel = {
        {1},
        {1},
        {1},
        {1}
    };
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

    return winner;
}

bool C4_Board::game_is_over() {
    return is_win() || is_draw();
}

bool C4_Board::is_draw() {
    return (n_moves == 42 && !is_win());
}

bool C4_Board::update_board(int x, int y, char symbol) {
    if (x < 0 || x >= this->columns){
        return false;
    }

    if (this->filled[x] < 0){
        return false;
    }

    this->board[this->filled[x]][x] = symbol;
    this->filled[x]--;
    this->n_moves++;

    return true;
}

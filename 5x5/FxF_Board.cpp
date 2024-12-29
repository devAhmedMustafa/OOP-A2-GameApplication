//
// Created by am180 on 12/16/2024.
//

#include "FxF_Board.h"
#include <iostream>
#include <iomanip>
#include "../Utils/GameTheory.h"

FxF_Board::FxF_Board(){
    rows = 5;
    columns = 5;

    board= new char*[rows]; //pointer to array of pointers
    for (int i = 0; i<rows ;i++){
        board[i]= new char[columns]; //array for each row
        for (int j=0; j<columns; j++){
            board[i][j]= '-'; //initialize cells
        }

    }
}

bool FxF_Board::update_board(int x, int y, char symbol) {

    if (x>= 0 && x<rows && y>=0 && y<columns && board[x][y] == '-'){
        board[x][y]= symbol;
        n_moves++;
        return true;
    }
    return false;
}

void FxF_Board::display_board() {

    cout << "  ";
    for (int i=0; i<columns; i++){
        cout << setw(3) << i+1;
    }

    cout << endl;

    for(int i=0; i<rows; i++){
        cout << setw(2) << i+1;
        for (int j=0; j<columns; j++){
            cout << setw(3) << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool FxF_Board::is_win() {
    vector<vector<int>> hKernel = {{1,1,1}};
    vector<vector<int>> vKernel = {
        {1},
        {1},
        {1}
    };
    vector<vector<int>> dKernel = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    vector<vector<int>> d2Kernel = {
        {0,0,1},
        {0,1,0},
        {1,0,0}
    };

    map<char, int> mapping = {{'X', 1}, {'O', -1}, {'-', 0}};
    auto normalized_board = GameTheory::normalizeBoard(board, 5, 5, mapping);

    auto win = GameTheory::checkWinner(normalized_board, {hKernel, vKernel, dKernel, d2Kernel}, 5, 5, 3);

    if (win == 1) {
        scores[0]++;
    } else if (win == -1) {
        scores[1]++;
    }

    if (n_moves == 24){
        if (scores[0] > scores[1]){
            cout << "Player X wins!" << endl;
        } else if (scores[0] < scores[1]){
            cout << "Player O wins!" << endl;
        } else {
            cout << "It's a draw!" << endl;
        }
    }

    return false;

}

bool FxF_Board::is_draw() {
    return (n_moves == 24);
}

bool FxF_Board::game_is_over() {
    return is_draw() || is_win();
}
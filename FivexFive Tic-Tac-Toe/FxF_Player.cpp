//
// Created by am180 on 12/16/2024.
//

#include "FxF_Player.h"

FxF_Player::FxF_Player(string name, char symbol) : Player<char>(name, symbol) {}

void FxF_Player::getmove(int &x, int &y) {
    cout << this->name << ", enter your move (row and column): ";
    int col, row;
    cin >> row >> col;

    x = row - 1;
    y = col - 1;
}
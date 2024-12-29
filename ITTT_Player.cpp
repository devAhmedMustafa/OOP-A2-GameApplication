//
// Created by Ahmed Mustafa on 12/16/2024.
//

#include "ITTT_Player.h"

ITTT_Player::ITTT_Player(string name, char symbol) : Player(name, symbol) {}

void ITTT_Player::getmove(int &x, int &y) {
    cout << "Enter your move (x y): ";
    int col, row;

    cin >> col >> row;

    x = col - 1;
    y = row - 1;
}

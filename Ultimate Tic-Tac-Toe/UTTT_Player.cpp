//
// Created by Ahmed Mustafa on 12/14/2024.
//

#include "UTTT_Player.h"

UTTT_Player::UTTT_Player(string name, char symbol) : Player(name, symbol) {}

UTTT_Player::UTTT_Player(char symbol) : Player(symbol) {}

void UTTT_Player::getmove(int &x, int &y) {
    cout << "Enter the x and y coordinates of your move: ";
    int col, row;
    cin >> col >> row;
    x = col - 1;
    y = row - 1;

}
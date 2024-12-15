//
// Created by Nour on 2024-12-15.
//
#include "PTTT_Player.h"

PTTT_Player::PTTT_Player(string name, char symbol) : Player(name, symbol) {}

PTTT_Player::PTTT_Player(char symbol) : Player(symbol) {}

void PTTT_Player::getmove(int &x, int &y) {
    cout << "Enter the x and y coordinates of your move: ";
    int col, row;
    cin >> col >> row;
    x = col - 1;
    y = row - 1;


//
// Created by Nour on 2024-12-15.
//

#include "WTTT_Player.h"

WTTT_Player::WTTT_Player(string name, char symbol) : Player(name, symbol) {}

void WTTT_Player::getmove(int &x, int &y) {

    cout << "Enter alphabet: ";
    char alphabet;
    cin >> alphabet;

    symbol = toupper(alphabet);

    cout << "Enter the x coordinate: ";
    cin >> x;
    cout << "Enter the y coordinate: ";
    cin >> y;

}
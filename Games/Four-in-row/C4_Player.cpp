//
// Created by Ahmed Mustafa on 12/12/2024.
//

#include "C4_Player.h"

C4_Player::C4_Player(char symbol) : Player(symbol) {}

C4_Player::C4_Player(string name, char symbol) : Player(name, symbol) {}

void C4_Player::getmove(int &x, int &y) {
    cout << "Enter the column number: ";

    int col = 0;

    cin >> col;

    while (col < 1 || col > 7) {
        cout << "Invalid column number. Enter a number between 1 and 7: ";
        cin >> col;
    }

    x = col-1;

    y = -1;
}
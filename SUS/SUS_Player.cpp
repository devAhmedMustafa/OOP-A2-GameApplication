//
// Created by Ahmed Mustafa on 12/14/2024.
//

#include "SUS_Player.h"



SUS_Player::SUS_Player(std::string name, char symbol) : Player(name, symbol) {}

SUS_Player::SUS_Player(char symbol) : Player(symbol) {}

void SUS_Player::getmove(int &x, int &y) {

    choose_symbol();

    cout << "Enter the row and column of your move: ";

    int row, col;

    cin >> row >> col;

    y = row - 1;
    x = col - 1;

}

void SUS_Player::choose_symbol() {
    char s = ' ';

    while(s != 'S' && s != 'U') {
        cout << "Enter S or U: ";
        cin >> s;
    }

    this->symbol = s;
}

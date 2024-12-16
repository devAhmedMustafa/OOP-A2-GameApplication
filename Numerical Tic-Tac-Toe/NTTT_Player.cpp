//
// Created by Ahmed Mustafa on 12/12/2024.
//

#include "NTTT_Player.h"

NTTT_Player::NTTT_Player(int symbol) : Player(symbol) {}

NTTT_Player::NTTT_Player(string name, int symbol) : Player(name, symbol) {}

void NTTT_Player::getmove(int &x, int &y) {

    cout << "Enter the row and column: ";
    int row, col;

    cin >> row >> col;
    while (row < 1 || row > 3 || col < 0 && col > 3) {
        cout << "Invalid indices" << endl;
        cout << "Enter the row and column: ";
        cin >> row >> col;
    }

    x = row-1;
    y = col-1;

    this->symbol = getNumber();

}

int NTTT_Player::getNumber() {
    cout << "Enter number to place: ";
    int number;
    cin >> number;

    if (symbol % 2 && number % 2 == 0 || number < 1 || number > 9) {
        cout << "Invalid number for player 1" << endl;
        return getNumber();
    }
    else if (symbol % 2 == 0 && number % 2 || number < 1 || number > 9) {
        cout << "Invalid number for player 2" << endl;
        return getNumber();
    }

    return number;
}


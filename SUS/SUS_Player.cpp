//
// Created by Ahmed Mustafa on 12/14/2024.
//

#include "SUS_Player.h"

#include "SUS_GuiHandler.h"
#include "../vendor/imgui/imgui.h"


SUS_Player::SUS_Player(std::string name, char symbol) : Player(name, symbol) {}

SUS_Player::SUS_Player(char symbol) : Player(symbol) {}

void SUS_Player::getmove(int &x, int &y) {


#ifndef GUI
    int row = -1, col = -1;
    choose_symbol();

    cout << "Enter the row and column of your move: ";


    cin >> row >> col;

#else

    if (SUS_GuiHandler::buttonClicked) {
        y = SUS_GuiHandler::y;
        x = SUS_GuiHandler::x;
        SUS_GuiHandler::reset();
    }
    else {
        x = -1;
        y = -1;
    }

#endif


}

void SUS_Player::choose_symbol() {
    char s = ' ';

#ifndef GUI
    while(s != 'S' && s != 'U') {
        cout << "Enter S or U: ";
        cin >> s;
    }
#endif

    this->symbol = s;
}

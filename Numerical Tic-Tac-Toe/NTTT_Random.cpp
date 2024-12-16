//
// Created by Ahmed Mustafa on 12/16/2024.
//

#include "NTTT_Random.h"

NTTT_Random::NTTT_Random(int symbol) : RandomPlayer(symbol) {}

void NTTT_Random::getmove(int &x, int &y) {

    int symbols[4] = {2, 4, 6, 8};

    x = rand() % 3;
    y = rand() % 3;

    int s = rand() % 4;
    this->symbol = symbols[s];

}

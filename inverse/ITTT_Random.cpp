//
// Created by Ahmed Mustafa on 12/16/2024.
//

#include "ITTT_Random.h"

ITTT_Random::ITTT_Random(char symbol) : RandomPlayer(symbol){}

void ITTT_Random::getmove(int &x, int &y) {
    x = rand() % 3;
    y = rand() % 3;
}


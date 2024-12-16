//
// Created by Ahmed Mustafa on 12/16/2024.
//

#include "UTTT_Random.h"


UTTT_Random::UTTT_Random(char symbol) : RandomPlayer(symbol){
    this->dimension = 9;
}

void UTTT_Random::getmove(int &x, int &y) {
    x = rand() % 9;
    y = rand() % 9;
}

//
// Created by Ahmed Mustafa on 12/16/2024.
//

#include "SUS_Random.h"

SUS_Random::SUS_Random(char symbol) : RandomPlayer(symbol) {
    this->dimension = 3;
}

void SUS_Random::getmove(int& x, int& y) {

    char symbols[2] = {'S', 'U'};

    x = rand() % 3;
    y = rand() % 3;

    int s = rand() % 2;
    this->symbol = symbols[s];

}

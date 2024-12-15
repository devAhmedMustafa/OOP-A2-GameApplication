//
// Created by Ahmed Mustafa on 12/15/2024.
//

#include "C4_Random.h"

C4_Random::C4_Random(char symbol) : C4_Player(symbol), RandomPlayer<char>(symbol) {
    this->dimension = 7;
}

void C4_Random::getmove(int &x, int &y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}
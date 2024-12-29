//
// Created by am180 on 12/16/2024.
//

#include "FxF_Random.h"

FxF_Random::FxF_Random(char symbol) : RandomPlayer(symbol) {}

void FxF_Random::getmove(int &x, int &y) {
    x = rand() % 5;
    y = rand() % 5;
}
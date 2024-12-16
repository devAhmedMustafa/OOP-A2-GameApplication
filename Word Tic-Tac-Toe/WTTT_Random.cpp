//
// Created by Nour on 2024-12-15.
//

#include "WTTT_Random.h"

WTTT_Random::WTTT_Random(char symbol) : RandomPlayer(symbol) {}

void WTTT_Random::getmove(int &x, int &y) {
    x = rand() % 3;
    y = rand() % 3;

    symbol = 'A' + rand() % 26;
}
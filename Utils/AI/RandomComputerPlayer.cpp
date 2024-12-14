//
// Created by Ahmed Mustafa on 12/14/2024.
//

#include "RandomComputerPlayer.h"

template <typename T>
RandomComputerPlayer<T>::RandomComputerPlayer(T symbol, int dimension) : RandomPlayer<T>(symbol) {
    this->dimension = dimension;
}

template <typename T>
void RandomComputerPlayer<T>::getmove(int &x, int &y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}

template class RandomComputerPlayer<int>;
template class RandomComputerPlayer<char>;
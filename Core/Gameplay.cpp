//
// Created by Ahmed Mustafa on 12/16/2024.
//

#include "Gameplay.h"

template<typename T>
Gameplay<T>::Gameplay() = default;

template<typename T>
Gameplay<T>::~Gameplay() {
    delete player1;
    delete player2;
    delete board;
    delete gm;
}

template<typename T>
void Gameplay<T>::play() {

    player1->setBoard(board);
    player2->setBoard(board);

    if (gm == nullptr)
        gm = new GameManager(board, new Player<T> *[2]{player1, player2});

    if (gm != nullptr)
        gm->run();
}

template<typename T>
void Gameplay<T>::UI() {}

template class Gameplay<char>;
template class Gameplay<int>;
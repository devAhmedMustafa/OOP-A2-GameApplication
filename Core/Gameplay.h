//
// Created by Ahmed Mustafa on 12/16/2024.
//
#pragma once

#include "Player.h"
#include "GameManager.h"

template <typename T>
class Gameplay {
public:
    static void play(Player<T>* player1, Player<T>* player2, Board<T>* board) {

        player1->setBoard(board);
        player2->setBoard(board);

        GameManager<T> gm(board, new Player<T> *[2]{player1, player2});
        gm.run();
    }
};

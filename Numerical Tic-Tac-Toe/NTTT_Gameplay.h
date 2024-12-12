//
// Created by Ahmed Mustafa on 12/12/2024.
//
#pragma once

#include "NTTT_Player.h"
#include "NTTT_Board.h"
#include "../Core/GameManager.h"

class NTTT_Gameplay{

public:

    static void play() {
        auto* player1 = new NTTT_Player("p1", 1);
        auto* player2 = new NTTT_Player("p2", 2);

        auto* board = new NTTT_Board();

        player1->setBoard(board);
        player2->setBoard(board);

        GameManager game_manager(board, new Player<int> *[2]{player1, player2});
        game_manager.run();
    }


};

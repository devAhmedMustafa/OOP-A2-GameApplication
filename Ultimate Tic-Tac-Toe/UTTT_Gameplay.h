//
// Created by Ahmed Mustafa on 12/14/2024.
//

#ifndef UTTT_GAMEPLAY_H
#define UTTT_GAMEPLAY_H

#include "UTTT_Board.h"
#include "UTTT_Player.h"
#include "../Core/GameManager.h"

class UTTT_Gameplay {
public:
    static void play() {
        auto* player1 = new UTTT_Player("p1", 'X');
        auto* player2 = new UTTT_Player("p2", 'O');

        auto* board = new UTTT_Board();

        player1->setBoard(board);
        player2->setBoard(board);

        GameManager game_manager(board, new Player<char> *[2]{player1, player2});
        game_manager.run();

    }
};



#endif //UTTT_GAMEPLAY_H

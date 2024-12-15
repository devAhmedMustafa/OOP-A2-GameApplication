//
// Created by Ahmed Mustafa on 12/14/2024.
//

#ifndef SUS_GAMEPLAY_H
#define SUS_GAMEPLAY_H
#include "SUS_Board.h"
#include "SUS_Player.h"
#include "../Core/GameManager.h"


class SUS_Gameplay {

public:
    static void play() {
        auto* player1 = new SUS_Player("p1", 'X');
        auto* player2 = new SUS_Player("p2", 'O');

        auto* board = new SUS_Board();

        player1->setBoard(board);
        player2->setBoard(board);

        GameManager game_manager(board, new Player<char> *[2]{player1, player2});
        game_manager.run();
    }

};



#endif //SUS_GAMEPLAY_H

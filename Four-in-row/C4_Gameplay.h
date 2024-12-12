//
// Created by Ahmed Mustafa on 12/12/2024.
//

#ifndef C4_GAMEPLAY_H
#define C4_GAMEPLAY_H

#include "C4_Board.h"
#include "C4_Player.h"
#include "../Core/GameManager.h"


class C4_Gameplay {
public:
    static void play() {
        auto* player1 = new C4_Player("p1", 'X');
        auto* player2 = new C4_Player("p2", 'O');

        auto* board = new C4_Board();

        player1->setBoard(board);
        player2->setBoard(board);

        GameManager game_manager(board, new Player<char> *[2]{player1, player2});
        game_manager.run();

    }
};



#endif //C4_GAMEPLAY_H

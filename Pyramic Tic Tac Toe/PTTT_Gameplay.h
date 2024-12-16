//
// Created by Ahmed Mustafa on 12/16/2024.
//

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "PTTT_Player.h"
#include "PTTT_Board.h"
#include "PTTT_Random.h"
#include "../Core/Gameplay.h"

class PTTT_Gameplay : Gameplay<char> {
public:

    static void UI() {
        cout << "Welcome to Pyramic Tic-Tac-Toe game!" << endl;

        auto *board = new PTTT_Board();

        string p1_name;

        cout << "Enter player 1 name: ";
        cin >> p1_name;

        cout << "Choose the game mode:" << endl;
        cout << "1. Player vs Player" << endl;
        cout << "2. Player vs Random" << endl;

        int action = 0;
        cin >> action;

        auto* player1 = new PTTT_Player(p1_name, 'X');
        auto* player2 = new PTTT_Player("Player 2", 'O');

        if (action == 1) {
            string p2_name;

            cout << "Enter player 2 name: ";
            cin >> p2_name;
            player2 = new PTTT_Player(p2_name, 'O');
        }
        else if (action == 2) {
            player2 = new PTTT_Random('O');
        }

        play(player1, player2, board);

        delete player1;
        delete player2;
        delete board;
    }
};


#endif //GAMEPLAY_H

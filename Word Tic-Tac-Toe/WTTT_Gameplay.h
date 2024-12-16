//
// Created by Ahmed Mustafa on 12/16/2024.
//

#ifndef WTTT_GAMEPLAY_H
#define WTTT_GAMEPLAY_H
#include "WTTT_Board.h"
#include "WTTT_Player.h"
#include "WTTT_Random.h"
#include "../Core/Gameplay.h"


class WTTT_Gameplay : public Gameplay<char> {
public:
    static void UI() {
        cout << "Welcome to Word Tic-Tac-Toe game!" << endl;

        auto *board = new WTTT_Board();

        string p1_name;

        cout << "Enter player 1 name: ";
        cin >> p1_name;

        cout << "Choose the game mode:" << endl;
        cout << "1. Player vs Player" << endl;
        cout << "2. Player vs Random" << endl;

        int action = 0;
        cin >> action;

        auto* player1 = new WTTT_Player(p1_name, 'X');
        Player<char>* player2 = nullptr;

        if (action == 1) {
            string p2_name;

            cout << "Enter player 2 name: ";
            cin >> p2_name;
            player2 = new WTTT_Player(p2_name, 'O');
        }
        else if (action == 2) {
            player2 = new WTTT_Random('O');
        }

        play(player1, player2, board);

        delete player1;
        delete player2;
        delete board;
    }
};



#endif //WTTT_GAMEPLAY_H

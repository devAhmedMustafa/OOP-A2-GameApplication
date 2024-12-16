//
// Created by Ahmed Mustafa on 12/14/2024.
//

#ifndef SUS_GAMEPLAY_H
#define SUS_GAMEPLAY_H
#include "SUS_Board.h"
#include "SUS_Player.h"
#include "SUS_Random.h"
#include "../Core/GameManager.h"
#include "../Core/Gameplay.h"


class SUS_Gameplay : public Gameplay<char> {
public:
    static void UI() {
        cout << "Welcome to SUS Tic-Tac-Toe game!" << endl;

        auto *board = new SUS_Board();

        string p1_name;

        cout << "Enter player 1 name: ";
        cin >> p1_name;

        cout << "Choose the game mode:" << endl;
        cout << "1. Player vs Player" << endl;
        cout << "2. Player vs Random" << endl;

        int action = 0;
        cin >> action;

        auto* player1 = new SUS_Player(p1_name, 'X');
        Player<char>* player2 = nullptr;

        if (action == 1) {
            string p2_name;

            cout << "Enter player 2 name: ";
            cin >> p2_name;
            player2 = new SUS_Player(p2_name, 'O');
        }
        else if (action == 2) {
            player2 = new SUS_Random('O');
        }

        play(player1, player2, board);

        delete player1;
        delete player2;
        delete board;
    }

};



#endif //SUS_GAMEPLAY_H

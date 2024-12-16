//
// Created by Ahmed Mustafa on 12/14/2024.
//

#ifndef UTTT_GAMEPLAY_H
#define UTTT_GAMEPLAY_H

#include "UTTT_Board.h"
#include "UTTT_Player.h"
#include "UTTT_Random.h"
#include "../Core/GameManager.h"
#include "../Core/Gameplay.h"

class UTTT_Gameplay : public Gameplay<char> {
public:

    UTTT_Gameplay() = default;

     void UI() {
        cout << "Welcome to Ultimate Tic-Tac-Toe game!" << endl;

        board = new UTTT_Board();

        string p1_name;

        cout << "Enter player 1 name: ";
        cin >> p1_name;

        cout << "Choose the game mode:" << endl;
        cout << "1. Player vs Player" << endl;
        cout << "2. Player vs Random" << endl;

        int action = 0;
        cin >> action;

        player1 = new UTTT_Player(p1_name, 'X');

        if (action == 1) {
            string p2_name;

            cout << "Enter player 2 name: ";
            cin >> p2_name;
            player2 = new UTTT_Player(p2_name, 'O');
        }
        else if (action == 2) {
            player2 = new UTTT_Random('O');
        }

        play();

    }
};



#endif //UTTT_GAMEPLAY_H

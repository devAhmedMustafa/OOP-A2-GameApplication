//
// Created by Ahmed Mustafa on 12/12/2024.
//
#pragma once

#include "NTTT_Player.h"
#include "NTTT_Board.h"
#include "NTTT_Random.h"
#include "../Core/GameManager.h"
#include "../Core/Gameplay.h"

class NTTT_Gameplay : public Gameplay<int>{

public:

    NTTT_Gameplay() = default;

     void UI() {
        cout << "Welcome to Numerical Tic-Tac-Toe game!" << endl;

        board = new NTTT_Board();

        string p1_name;

        cout << "Enter player 1 name: ";
        cin >> p1_name;

        cout << "Choose the game mode:" << endl;
        cout << "1. Player vs Player" << endl;
        cout << "2. Player vs Random" << endl;

        int action = 0;
        cin >> action;

        player1 = new NTTT_Player(p1_name, 1);

        if (action == 1) {
            string p2_name;

            cout << "Enter player 2 name: ";
            cin >> p2_name;
            player2 = new NTTT_Player(p2_name, 2);
        }
        else if (action == 2) {
            player2 = new NTTT_Random(2);
        }

        play();

    }


};

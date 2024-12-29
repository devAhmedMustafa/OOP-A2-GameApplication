//
// Created by Ahmed Mustafa on 12/16/2024.
//
#pragma once

#include "ITTT_Board.h"
#include "ITTT_Player.h"
#include "ITTT_Random.h"
#include "../Core/Gameplay.h"


class ITTT_Gameplay : public Gameplay<char> {
public:

    ITTT_Gameplay() = default;
    ~ITTT_Gameplay() override {}

    void UI() override {
        cout << "Welcome to Inverse Tic-Tac-Toe game!" << endl;

        board = new ITTT_Board();

        string p1_name;

        cout << "Enter player 1 name: ";
        cin >> p1_name;

        cout << "Choose the game mode:" << endl;
        cout << "1. Player vs Player" << endl;
        cout << "2. Player vs Random" << endl;

        int action = 0;
        cin >> action;

        player1 = new ITTT_Player(p1_name, 'X');

        if (action == 1) {
            string p2_name;

            cout << "Enter player 2 name: ";
            cin >> p2_name;
            player2 = new ITTT_Player(p2_name, 'O');
        }
        else if (action == 2) {
            player2 = new ITTT_Random('O');
        }

        play();
    }
};


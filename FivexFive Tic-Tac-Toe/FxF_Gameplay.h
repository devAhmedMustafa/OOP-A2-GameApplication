//
// Created by am180 on 12/16/2024.
//

#ifndef GAMEAPPLICATION_FXF_GAMEPLAY_H
#define GAMEAPPLICATION_FXF_GAMEPLAY_H

#include "../Core/Gameplay.h"
#include "FxF_Board.h"
#include "FxF_Player.h"
#include "FxF_Random.h"

class FxF_Gameplay : public Gameplay<char> {
public:

    FxF_Gameplay() = default;

    void UI(){
        cout << "Welcome to 5x5 Tic-Tac-Toe game!" << endl;

        board = new FxF_Board();

        string p1_name;

        cout << "Enter player 1 name: ";
        cin >> p1_name;

        cout << "Choose the game mode:" << endl;
        cout << "1. Player vs Player" << endl;
        cout << "2. Player vs Random" << endl;

        int action = 0;
        cin >> action;

        player1 = new FxF_Player(p1_name, 'X');

        if (action == 1) {
            string p2_name;

            cout << "Enter player 2 name: ";
            cin >> p2_name;
            player2 = new FxF_Player(p2_name, 'O');
        }
        else if (action == 2) {
            player2 = new FxF_Random('O');
        }

        play();

    }
};


#endif //GAMEAPPLICATION_FXF_GAMEPLAY_H

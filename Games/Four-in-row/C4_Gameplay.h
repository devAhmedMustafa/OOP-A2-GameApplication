//
// Created by Ahmed Mustafa on 12/12/2024.
//

#ifndef C4_GAMEPLAY_H
#define C4_GAMEPLAY_H

#include "C4_ai.h"
#include "C4_Board.h"
#include "C4_Player.h"
#include "C4_Random.h"
#include "../Core/GameManager.h"
#include "../Core/Gameplay.h"


class C4_Gameplay : public Gameplay<char> {
public:

    C4_Gameplay() {}
    ~C4_Gameplay() override {}

     void UI() {

        board = new C4_Board();

        string p1_name;

        cout << "Enter player 1 name: ";
        cin >> p1_name;

        cout << "Welcome to Four-in-a-row game!" << endl;
        cout << "Choose the game mode:" << endl;
        cout << "1. Player vs Player" << endl;
        cout << "2. Player vs AI" << endl;
        cout << "3. Player vs Random" << endl;

        int action = 0;
        cin >> action;

        player1 = new C4_Player(p1_name, 'X');

        if (action == 1) {
            string p2_name;

            cout << "Enter player 2 name: ";
            cin >> p2_name;
            player2 = new C4_Player(p2_name, 'O');
        }
        else if (action == 2) {
            player2 = new C4_ai('O', dynamic_cast<C4_Board &>(*board));
        }
        else if (action == 3) {
            player2 = new C4_Random('O');
        }

        play();

    }
};



#endif //C4_GAMEPLAY_H

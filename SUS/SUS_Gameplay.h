//
// Created by Ahmed Mustafa on 12/14/2024.
//

#ifndef SUS_GAMEPLAY_H
#define SUS_GAMEPLAY_H
#include "SUS_Board.h"
#include "SUS_Player.h"
#include "SUS_Random.h"
#include "../Core/Gameplay.h"
#include "../Utils/RAII.h"
#include "../vendor/imgui/imgui.h"


class SUS_Gameplay : public Gameplay<char> {
public:
    static void UI() {
        auto *board = new SUS_Board();

        string p1_name;

        static int steps = 0;
        static int action = 0;

#ifndef GUI
        cout << "Welcome to SUS Tic-Tac-Toe game!" << endl;



        cout << "Enter player 1 name: ";
        cin >> p1_name;

        cout << "Choose the game mode:" << endl;
        cout << "1. Player vs Player" << endl;
        cout << "2. Player vs Random" << endl;

        cin >> action;
#endif

#ifndef CLI

        // ImGui::End();
        RAII susGame;
        susGame.Begin("SUS Tic-Tac-Toe");

        if (steps == 0) {
            ImGui::Text("Welcome to SUS Tic-Tac-Toe game!");
            steps++;
        }

        else if (steps == 1) {
            static char name_buffer[256] = "";
            ImGui::Text("Enter player 1 name:");
            ImGui::InputText("#p1_name:", name_buffer, 256);

            if (ImGui::Button("Submit") && strlen(name_buffer) > 0) {
                p1_name = name_buffer;
                steps++;
            }
        }

        else if (steps == 2) {
            ImGui::Text("Choose the game mode:");
            if (ImGui::Button("Player vs Player")) {
                action = 1;
                steps++;
            }
            if (ImGui::Button("Player vs Random")) {
                action = 2;
                steps++;
            }
        }

#endif


#ifndef CLI
        if (steps != 3) {
            return;
        }
#endif


        auto* player1 = new SUS_Player(p1_name, 'X');
        Player<char>* player2 = nullptr;

        if (action == 1) {
            string p2_name;
#ifndef GUI
            cout << "Enter player 2 name: ";
            cin >> p2_name;
#endif

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

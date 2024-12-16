#include <iostream>
#include <vector>

#include "Four-in-row/C4_Gameplay.h"
#include "Numerical Tic-Tac-Toe/NTTT_Gameplay.h"
#include "Pyramic Tic Tac Toe/PTTT_Gameplay.h"
#include "SUS/SUS_Gameplay.h"
#include "Ultimate Tic-Tac-Toe/UTTT_Gameplay.h"

void func() {

}

using namespace std;

int main() {

    auto a = func;

    while(true) {
        cout << "Welcome to Game Application!" << endl;
        vector<string> games_names = {"Pyramic Tic-Tac-Toe", "Four in row", "Numerical Tic-Tac-Toe", "Ultimate Tic-Tac-Toe", "SUS Tic-Tac-Toe"};

        vector games = {
            PTTT_Gameplay::UI,
            C4_Gameplay::UI,
            NTTT_Gameplay::UI,
            UTTT_Gameplay::UI,
            SUS_Gameplay::UI
        };

        cout << "Choose a game to play: " << endl;

        int i;
        for (i = 0; i < games_names.size(); i++){
            cout << i + 1 << ". " << games_names[i] << endl;
        }
        cout << i+1 << ". Exit" << endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == i+1){
            break;
        }

        auto game = games[choice-1];
        game();

    }


    return 0;
}

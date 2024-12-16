#include "GameManager.h"

#include "../vendor/imgui/imgui.h"

template <typename T>
GameManager<T>::GameManager(Board<T>* bPtr, Player<T>* playerPtr[2]) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

template <typename T>
void GameManager<T>::run() {
    int x=-1, y=-1;

#ifndef GUI

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i : {0, 1}) {
            players[i]->getmove(x, y);
            while (!boardPtr->update_board(x, y, players[i]->getsymbol())) {
                cout << "Invalid move. Try again\n";
                players[i]->getmove(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_win()) {
                cout << players[i]->getname() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()) {
                cout << "Draw!\n";
                return;
            }
        }
    }

#else


    switch (currentState) {

        case GameState::PlayerTurn:
            cout << "Player turn" << endl;
            boardPtr->display_board();

            players[currentPlayer]->getmove(x, y);
            if (x >= 0 && y >= 0) {
                cout << "Player " << currentPlayer << " moved to " << x << ", " << y << endl;
                currentState = GameState::UpdateBoard;
            }
            break;

        case GameState::UpdateBoard:
            cout << "Update board" << endl;
            if (!boardPtr->update_board(x, y, players[currentPlayer]->getsymbol())) {
                cout << "Invalid move. Try again\n";
                // Invalid move, retry
                currentState = GameState::PlayerTurn;
            } else {
                currentState = GameState::CheckWin;
            }
            break;

        case GameState::CheckWin:
            cout << "Check win" << endl;

            if (boardPtr->is_win()) {
                ImGui::Text("%s wins!", players[currentPlayer]->getname().c_str());
                currentState = GameState::GameOver;
            } else if (boardPtr->is_draw()) {
                ImGui::Text("It's a draw!");
                currentState = GameState::GameOver;
            } else {
                currentPlayer = 1 - currentPlayer;
                currentState = GameState::PlayerTurn;
            }
            break;

        case GameState::GameOver:
            cout << "Game over" << endl;
            if (ImGui::Button("Restart")) {
                restartGame();
            }
            break;

    }
#endif

}

template <typename T>
void GameManager<T>::restartGame() {
    currentState = GameState::PlayerTurn;
    currentPlayer = 0;
}

template class GameManager<int>;
template class GameManager<char>;

#include "GameManager.h"

GameManager::GameManager(Board &board) : board(&board) {
    this->player1 = new Player("Name 1", board.getSymbols()[0]);
    this->player2 = new Player("Name 2", board.getSymbols()[1]);
}

void GameManager::swapPlayers() {
    currentPlayer = (1-currentPlayer);
}

void GameManager::run() {

    while(!board->isOver()){

        board->print();

        this->swapPlayers();

        if (board->checkForWinner() != 'Q'){
            return;
        }

    }

}
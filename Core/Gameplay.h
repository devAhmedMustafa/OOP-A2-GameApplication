//
// Created by Ahmed Mustafa on 12/16/2024.
//
#pragma once

#include "Player.h"
#include "GameManager.h"

template <typename T>
class Gameplay {

protected:
    Player<T> *player1{nullptr}, *player2{nullptr};
    Board<T>* board{nullptr};
    GameManager<T>* gm{nullptr};

public:

    Gameplay();

    virtual ~Gameplay();

    void play();
    virtual void UI();
};

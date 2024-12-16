//
// Created by am180 on 12/16/2024.
//

#ifndef GAMEAPPLICATION_FXF_PLAYER_H
#define GAMEAPPLICATION_FXF_PLAYER_H

#include "../Core/Player.h"

class FxF_Player : public Player<char> {
public:
    // Constructor to initialize the player with a name and symbol
    FxF_Player(string name, char symbol);

    // Implementation of the pure virtual getmove method
    void getmove(int& x, int& y) override;
};


#endif //GAMEAPPLICATION_FXF_PLAYER_H

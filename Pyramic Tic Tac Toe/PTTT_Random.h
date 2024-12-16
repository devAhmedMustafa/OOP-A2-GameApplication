//
// Created by Nour on 2024-12-15.
//

#ifndef GAMEAPPLICATION_PTTT_RANDOM_H
#define GAMEAPPLICATION_PTTT_RANDOM_H
#include "PTTT_Player.h"
#include "../Core/RandomPlayer.h"

class PTTT_Random : public PTTT_Player, public RandomPlayer<char> {
public:
    PTTT_Random(char symbol);
    void getmove(int &x, int &y) override;
};


#endif //GAMEAPPLICATION_PTTT_RANDOM_H

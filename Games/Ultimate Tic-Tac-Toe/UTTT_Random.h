//
// Created by Ahmed Mustafa on 12/16/2024.
//

#ifndef UTTT_RANDOM_H
#define UTTT_RANDOM_H
#include "UTTT_Player.h"
#include "../Core/RandomPlayer.h"


class UTTT_Random : public RandomPlayer<char> {
public:
    UTTT_Random(char symbol);

    void getmove(int &x, int &y) override;
};



#endif //UTTT_RANDOM_H

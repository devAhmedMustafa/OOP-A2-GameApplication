//
// Created by Ahmed Mustafa on 12/15/2024.
//

#ifndef C4_RANDOM_H
#define C4_RANDOM_H
#include "C4_Player.h"
#include "../Core/RandomPlayer.h"


class C4_Random : public RandomPlayer<char> {
public:
    C4_Random(char symbol);
    void getmove(int &x, int &y) override;
};



#endif //C4_RANDOM_H

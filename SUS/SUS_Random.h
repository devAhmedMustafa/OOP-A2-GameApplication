//
// Created by Ahmed Mustafa on 12/16/2024.
//

#ifndef SUS_RANDOM_H
#define SUS_RANDOM_H
#include "SUS_Player.h"
#include "../Core/RandomPlayer.h"


class SUS_Random :  public RandomPlayer<char>{
public:
    SUS_Random(char symbol);

    void getmove(int &x, int &y) override;
};



#endif //SUS_RANDOM_H

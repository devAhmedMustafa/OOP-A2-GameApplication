//
// Created by Nour on 2024-12-15.
//

#ifndef GAMEAPPLICATION_WTTT_RANDOM_H
#define GAMEAPPLICATION_WTTT_RANDOM_H
#include "../Core/RandomPlayer.h"


class WTTT_Random : public RandomPlayer<char> {
public:
    WTTT_Random(char symbol);
    void getmove(int &x, int &y) override;
};


#endif //GAMEAPPLICATION_WTTT_RANDOM_H

//
// Created by Ahmed Mustafa on 12/16/2024.
//

#ifndef NTTT_RANDOM_H
#define NTTT_RANDOM_H
#include "NTTT_Player.h"
#include "../Core/RandomPlayer.h"


class NTTT_Random : public RandomPlayer<int> {
public:
    NTTT_Random(int symbol);
    void getmove(int &x, int &y) override;
};



#endif //NTTT_RANDOM_H

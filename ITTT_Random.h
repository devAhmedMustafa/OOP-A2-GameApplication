//
// Created by Ahmed Mustafa on 12/16/2024.
//

#ifndef ITTT_RANDOM_H
#define ITTT_RANDOM_H
#include "../Core/RandomPlayer.h"


class ITTT_Random : public RandomPlayer<char> {
public:
    ITTT_Random(char symbol);
    void getmove(int &x, int &y) override;
};



#endif //ITTT_RANDOM_H

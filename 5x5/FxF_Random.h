//
// Created by am180 on 12/16/2024.
//

#ifndef GAMEAPPLICATION_FXF_RANDOM_H
#define GAMEAPPLICATION_FXF_RANDOM_H

#include "../Core/RandomPlayer.h"

class FxF_Random : public RandomPlayer<char> {
public:
    FxF_Random(char symbol);

    void getmove(int &x, int &y) override;
};


#endif //GAMEAPPLICATION_FXF_RANDOM_H

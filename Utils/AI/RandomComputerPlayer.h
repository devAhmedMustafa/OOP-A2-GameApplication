//
// Created by Ahmed Mustafa on 12/14/2024.
//

#ifndef RANDOMCOMPUTERPLAYER_H
#define RANDOMCOMPUTERPLAYER_H
#include "../../Core/RandomPlayer.h"


template <typename T>
class RandomComputerPlayer : public RandomPlayer<T> {
public:
    RandomComputerPlayer(T symbol, int dimension);
    void getmove(int& x, int& y) override;
};



#endif //RANDOMCOMPUTERPLAYER_H

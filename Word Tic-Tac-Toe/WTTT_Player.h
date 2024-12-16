//
// Created by Nour on 2024-12-15.
//

#ifndef GAMEAPPLICATION_WTTT_PLAYER_H
#define GAMEAPPLICATION_WTTT_PLAYER_H
#include "../Core/Player.h"


class WTTT_Player : public Player<char> {
public:
    WTTT_Player(string name,char symbol);
    void getmove(int &x, int &y) override;
};


#endif //GAMEAPPLICATION_WTTT_PLAYER_H

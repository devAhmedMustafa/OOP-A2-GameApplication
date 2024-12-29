//
// Created by Ahmed Mustafa on 12/16/2024.
//

#ifndef ITTT_PLAYER_H
#define ITTT_PLAYER_H
#include "../Core/Player.h"


class ITTT_Player : public Player<char> {
public:
    ITTT_Player(string name, char symbol);

    void getmove(int &x, int &y) override;
};



#endif //ITTT_PLAYER_H

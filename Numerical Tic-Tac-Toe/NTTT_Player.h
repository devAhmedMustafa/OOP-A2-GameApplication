//
// Created by Ahmed Mustafa on 12/12/2024.
//

#ifndef NTTT_PLAYER_H
#define NTTT_PLAYER_H
#include "../Core/Player.h"


class NTTT_Player : public Player<int> {
public:
    NTTT_Player(string name, int symbol);
    NTTT_Player(int symbol);
    void getmove(int &x, int &y) override;
};



#endif //NTTT_PLAYER_H

//
// Created by Ahmed Mustafa on 12/14/2024.
//

#ifndef UTTT_PLAYER_H
#define UTTT_PLAYER_H
#include "../Core/Player.h"


class UTTT_Player : public Player<char> {
public:

    UTTT_Player(string name, char symbol);
    UTTT_Player(char symbol);

    void getmove(int &x, int &y) override;
};



#endif //UTTT_PLAYER_H

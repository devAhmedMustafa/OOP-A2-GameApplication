//
// Created by Ahmed Mustafa on 12/14/2024.
//

#ifndef SUS_PLAYER_H
#define SUS_PLAYER_H
#include "../Core/Player.h"


class SUS_Player : public Player<char> {
public:
    SUS_Player(string name, char symbol);
    SUS_Player(char symbol);

    void getmove(int &x, int &y) override;

    void choose_symbol();
};



#endif //SUS_PLAYER_H

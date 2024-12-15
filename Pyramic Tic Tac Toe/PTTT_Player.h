//
// Created by Nour on 2024-12-15.
//

#ifndef GAMEAPPLICATION_PTTT_BOARD_H
#define GAMEAPPLICATION_PTTT_BOARD_H
#include "../Core/Player.h"

class PTTT_Player : public Player<char> {
public:

    PTTT_Player(string name, char symbol);
    PTTT_Player(char symbol);

    void getmove(int &x, int &y) override;
};


#endif //GAMEAPPLICATION_PTTT_BOARD_H

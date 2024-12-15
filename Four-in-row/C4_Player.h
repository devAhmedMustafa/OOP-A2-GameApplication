//
// Created by Ahmed Mustafa on 12/12/2024.
//

#ifndef C4_PLAYER_H
#define C4_PLAYER_H
#include "../Core/Player.h"

class C4_Player : public Player<char> {
public:
    C4_Player(char symbol);
    C4_Player(string name, char symbol);

    void getmove(int &x, int &y) override;

};



#endif //C4_PLAYER_H

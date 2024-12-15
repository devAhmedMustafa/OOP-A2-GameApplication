//
// Created by Nour on 2024-12-15.
//

#include "PTTT_Random.h"

PTTT_Random::PTTT_Random(char symbol) : PTTT_Player(symbol), RandomPlayer<char>(symbol) {
    this->dimension = 5;
}

void PTTT_Random::getmove(int &y, int &x) { // Swapped x and y
    while (true) {
        y = rand() % 3; // 3 rows in the pyramid
        if (y == 0) {
            x = 2; // Row 0 has only column 2
        } else if (y == 1) {
            x = 1 + rand() % 3; // Row 1 has columns 1, 2, 3
        } else if (y == 2) {
            x = rand() % 5; // Row 2 has columns 0, 1, 2, 3, 4
        }

        // Check if the position is empty using a hypothetical `is_valid_move` method
        if (this->is_valid_move(x, y)) {
            break; // Valid position found
        }
    }
}

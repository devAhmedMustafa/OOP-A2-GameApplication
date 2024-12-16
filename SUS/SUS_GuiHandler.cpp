//
// Created by Ahmed Mustafa on 12/16/2024.
//

#include "SUS_GuiHandler.h"

void SUS_GuiHandler::set_x(int x) {
    SUS_GuiHandler::x = x;
    buttonClicked = true;
}

void SUS_GuiHandler::set_y(int y) {
    SUS_GuiHandler::y = y;
}

void SUS_GuiHandler::reset() {
    x = -1;
    y = -1;
    buttonClicked = false;
}

int SUS_GuiHandler::x = -1;
int SUS_GuiHandler::y = -1;
bool SUS_GuiHandler::buttonClicked = false;

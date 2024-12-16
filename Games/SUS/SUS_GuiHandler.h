//
// Created by Ahmed Mustafa on 12/16/2024.
//

#ifndef SUS_GUIHANDLER_H
#define SUS_GUIHANDLER_H



class SUS_GuiHandler {
public:
    static int x, y;
    static bool buttonClicked;

    void static set_x(int x);
    void static set_y(int y);
    void static reset();
};

#endif //SUS_GUIHANDLER_H

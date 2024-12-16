//
// Created by Ahmed Mustafa on 12/16/2024.
//

#ifndef GUIMANAGER_H
#define GUIMANAGER_H



class GuiManager {
public:

    static int selected_game;
    static int selected_mode;

    static void init();
    static void render();
    static void shutdown();
};



#endif //GUIMANAGER_H

//
// Created by Ahmed Mustafa on 12/16/2024.
//

#ifndef RAII_H
#define RAII_H
#include "../vendor/imgui/imgui.h"


class RAII {
public:
    RAII() : active(false) {}

    void Begin(const char* name) {
        active = ImGui::Begin(name);
    }

    ~RAII() {
        if (active) {
            ImGui::End();
        }
    }

private:
    bool active;
};



#endif //RAII_H

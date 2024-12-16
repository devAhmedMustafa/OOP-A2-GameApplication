
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Four-in-row/C4_Gameplay.h"
#include "Numerical Tic-Tac-Toe/NTTT_Gameplay.h"
#include "Pyramic Tic Tac Toe/PTTT_Gameplay.h"
#include "SUS/SUS_Gameplay.h"
#include "Ultimate Tic-Tac-Toe/UTTT_Gameplay.h"
#include "Utils/RAII.h"
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw_gl3.h"
#include "Word Tic-Tac-Toe/WTTT_Gameplay.h"

using namespace std;

vector<string> games_names = {"Pyramic Tic-Tac-Toe", "Four in row", "Numerical Tic-Tac-Toe", "Ultimate Tic-Tac-Toe", "SUS Tic-Tac-Toe", "Word Tic-Tac-Toe"};

#pragma region UI

PTTT_Gameplay pttt;
C4_Gameplay c4;
NTTT_Gameplay nttt;
UTTT_Gameplay uttt;
SUS_Gameplay sus;
WTTT_Gameplay wttt;

void pttt_ui() {
    pttt.UI();
}

void c4_ui() {
    c4.UI();
}

void nttt_ui() {
    nttt.UI();
}

void uttt_ui() {
    uttt.UI();
}

void sus_ui() {
    sus.UI();
}

void wttt_ui() {
    wttt.UI();
}

#pragma endregion

vector games = { pttt_ui, c4_ui, nttt_ui, uttt_ui, sus_ui, wttt_ui };

void cli_menu();
void gui_menu();

int main() {

#ifndef GUI
    cli_menu();
#endif

#ifndef CLI
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(640, 480, "Game Application", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(3);

    if (glewInit() != GLEW_OK)
        return -1;

    ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init(window, true);
    ImGui::StyleColorsDark();

    while (!glfwWindowShouldClose(window)) {
        ImGui_ImplGlfwGL3_NewFrame();

        gui_menu();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();

#endif

    return 0;
}

void cli_menu() {
    while(true) {
        cout << "Welcome to Game Application!" << endl;
        cout << "Choose a game to play: " << endl;

        int i;
        for (i = 0; i < games_names.size(); i++){
            cout << i + 1 << ". " << games_names[i] << endl;
        }
        cout << i+1 << ". Exit" << endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == i+1){
            break;
        }

        auto game = games[choice-1];
        game();

    }
}

void gui_menu() {

    static int activated = -1;

    RAII games_window;
    games_window.Begin("Games Menu");

    for (int i = 0; i < games_names.size(); i++) {
        if (ImGui::Button(games_names[i].c_str())) {
            activated = i;
        }
    }

    if (activated == -1) {
        return;
    }

    const auto game = games[activated];
    game();
}
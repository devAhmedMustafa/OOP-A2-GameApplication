
#include "Four-in-row/C4_Gameplay.h"
#include "Utils/AI/Connect4Agent.h"
#include "Utils/AI/Network.h"
#include "Four-in-row/C4_Board.h"
#include "Utils/AI/RandomComputerPlayer.h"

void printProgressBar(int progress, int total) {
    int barWidth = 50;
    float percentage = (float)progress / total;

    // Calculate the number of "done" symbols
    int pos = barWidth * percentage;

    // Print the progress bar and overwrite it each time
    cout << "\r[";
    for (int i = 0; i < barWidth; i++) {
        if (i < pos) {
            cout << "=";
        } else if (i == pos) {
            cout << ">";
        } else {
            cout << " ";
        }
    }
    cout << "] " << int(percentage * 100) << " %";
    cout.flush();
}

int start_practising() {

    size_t buffer_size = 10000;
    float lr = 0.001;
    float epsilon = 1.0;
    float gamma = 0.99;
    int batch_size = 4;
    const int episodes = 1000;
    size_t target_update = 10;

    Connect4Agent agent(buffer_size, lr, epsilon, gamma, batch_size);
    RandomComputerPlayer random_player('O', 7);
    C4_Player player("Ahmed", 'O');

    float total_reward = 0;
    int total_wins = 0;
    int total_losses = 0;

    for (int i = 0; i < episodes; i++) {

        C4_Board board;

        // cout << "Episode: " << i << " Total Reward: " << total_reward << endl;

        int x, y=-1;

        bool random_player_starts = (i % 2 == 0);

        while (!board.game_is_over()) {

            auto state = board.flatten_board();

            if (random_player_starts) {
                if (i == episodes-1) {
                    board.display_board();
                    player.getmove(x, y);
                    while (!board.update_board(x, y, player.getsymbol())) {
                        player.getmove(x, y);
                    }
                }
                else {
                    random_player.getmove(x, y);
                    while (!board.update_board(x, y, random_player.getsymbol())) {
                        random_player.getmove(x, y);
                    }
                }
                random_player_starts = false;
            } else {
                const auto state_tensor = torch::tensor(state);
                auto action = agent.take_action(state_tensor);

                x = action;
                while (!board.update_board(x, y, 'X')) {
                    action = agent.take_action(state_tensor);
                    x = action;
                }
                random_player_starts = true;
            }

            float reward = board.is_win() ? (random_player_starts ? 1.0f : -1.0f) : 0;

            if (reward == 1) {
                total_wins++;
            } else if (reward == -1) {
                total_losses++;
            }

            if (board.game_is_over()) {
                agent.replay_buffer.add(state, 0, reward, state);
                agent.train();
                total_reward += reward;
                break;
            }

            const vector<float> next_state = board.flatten_board();
            agent.replay_buffer.add(state, x, reward, next_state);
            agent.train();
            total_reward += reward;
        }

        if (epsilon > 0.1) epsilon *= 0.99;

        if (i % target_update == 0) {
            agent.update_target();
        }

        printProgressBar(i, episodes);

    }
    cout << endl;

    cout << "Total Games: " << episodes << endl;
    cout << "Total Wins: " << total_wins << " Total Losses: " << total_losses << endl;
    cout << "Win Rate: " << (float)total_wins / episodes << " Loss Rate: " << (float)total_losses / episodes << endl;

    cout << "Training is over!" << endl;
    return 0;

}

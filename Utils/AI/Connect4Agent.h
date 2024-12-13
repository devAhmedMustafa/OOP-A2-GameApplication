//
// Created by Ahmed Mustafa on 12/11/2024.
//

#ifndef CONNECT4AGENT_H
#define CONNECT4AGENT_H
#include "Network.h"
#include "ReplayBuffer.h"

class Connect4Agent {

public:


    Network policy, target;
    ReplayBuffer replay_buffer;
    float epsilon;
    float gamma;
    optim::Adam optimizer;
    size_t batch_size;


    Connect4Agent(size_t buffer_size, float lr, float epsilon, float gamma, size_t batch_size);
    int take_action(torch::Tensor state, bool explore = true);
    void train();
    void update_target();
    void save(std::string path);

};

#endif //CONNECT4AGENT_H

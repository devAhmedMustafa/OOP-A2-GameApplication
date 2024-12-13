#include "Connect4Agent.h"

Connect4Agent::Connect4Agent(size_t buffer_size, float lr, float epsilon, float gamma, size_t batch_size)
    : replay_buffer(buffer_size), epsilon(epsilon), gamma(gamma), batch_size(batch_size),
    optimizer(policy.parameters(), lr)
{
    target = policy;
}

int Connect4Agent::take_action(torch::Tensor state, bool explore) {
    if (explore && (rand() / (RAND_MAX + 1.0)) < epsilon) {
        return rand() % 7;
    }
    auto action = policy.forward(state).argmax(1).item<int>();
    return action;
}

void Connect4Agent::train() {
    if (!replay_buffer.is_ready(batch_size)) {
        return;
    }

    auto batch = replay_buffer.sample(batch_size);
    vector<torch::Tensor> states, actions, rewards, next_states;

    for (auto& [s, a, r, ns] : batch) {
        states.push_back(torch::tensor(s));
        actions.push_back(torch::tensor(a));
        rewards.push_back(torch::tensor(r));
        next_states.push_back(torch::tensor(ns));
    }

    auto states_tensor = torch::stack(states);
    auto actions_tensor = torch::stack(actions);
    auto rewards_tensor = torch::stack(rewards);
    auto next_states_tensor = torch::stack(next_states);

    auto q_values = policy.forward(states_tensor).gather(1, actions_tensor);
    auto [next_q_values, _] = target.forward(next_states_tensor).max(1);
    auto target_q_values = rewards_tensor + gamma * next_q_values;

    auto loss = torch::mse_loss(q_values, target_q_values.unsqueeze(1));

    optimizer.zero_grad();
    loss.backward();
    optimizer.step();

}

void Connect4Agent::update_target() {
    torch::NoGradGuard no_grad;
    for (size_t i = 0; i < policy.parameters().size(); i++) {
        target.parameters()[i].copy_(policy.parameters()[i]);
    }
}
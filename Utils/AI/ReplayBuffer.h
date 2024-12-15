//
// Created by Ahmed Mustafa on 12/10/2024.
//

#ifndef REPLAYBUFFER_H
#define REPLAYBUFFER_H

#include <deque>
#include <random>
#include <algorithm>
#include <vector>
#include <tuple>

#define state_tuple tuple<vector<float>, int, float, vector<float>>

using namespace std;

class ReplayBuffer {

    deque<state_tuple> buffer;
    size_t capacity;

public:
    ReplayBuffer(size_t capacity) : capacity(capacity) {}

    void add(vector<float> state, int action, float reward, vector<float> next_state) {
        if (buffer.size() >= capacity) {
            buffer.pop_front();
        }
        buffer.emplace_back(state, action, reward, next_state);
    }

    vector<state_tuple> sample(int batch_size) {
        vector<state_tuple> batch;
        std::sample(buffer.begin(), buffer.end(), back_inserter(batch), batch_size, std::mt19937{ std::random_device{}() });
        return batch;
    }

    bool is_ready(int batch_size) const {
        return buffer.size() >= batch_size;
    }

};

#endif //REPLAYBUFFER_H

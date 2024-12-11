//
// Created by Ahmed Mustafa on 12/10/2024.
//

#ifndef NETWORK_H
#define NETWORK_H

#include <torch/torch.h>


struct Network final : torch::nn::Module {
    torch::nn::Linear fc1{nullptr}, fc2{nullptr}, fc3{nullptr};

    Network() {
        fc1 = register_module("fc1", torch::nn::Linear(42, 128));
        fc2 = register_module("fc2", torch::nn::Linear(128, 128));
        fc3 = register_module("fc3", torch::nn::Linear(128, 7));
    }

    torch::Tensor forward(torch::Tensor x) {
        x = torch::relu(fc1(x));
        x = torch::relu(fc2(x));
        x = fc3(x);
        return x;
    }
};



#endif //NETWORK_H

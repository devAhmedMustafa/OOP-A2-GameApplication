//
// Created by Ahmed Mustafa on 12/10/2024.
//

#ifndef NETWORK_H
#define NETWORK_H

#include <torch/torch.h>

using namespace torch;

struct Network : nn::Module {

    nn::Linear fc1{nullptr}, fc2{nullptr}, fc3{nullptr};

    Network() {
        fc1 = register_module("fc1", nn::Linear(42, 128));
        fc2 = register_module("fc2", nn::Linear(128, 128));
        fc3 = register_module("fc3", nn::Linear(128, 7));
    }

    Tensor forward(Tensor x) {
        x = relu(fc1(x));
        x = relu(fc2(x));
        x = fc3(x);
        return x;
    }
};



#endif //NETWORK_H

//
// Created by Ahmed Mustafa on 12/10/2024.
//

#ifndef NETWORK_H
#define NETWORK_H

#include <torch/torch.h>

using namespace torch;

struct Network : nn::Module {

    nn::Linear fc1{42, 128}, fc2{128, 128}, fc3{128, 7};

    Network() {

    }

    Tensor forward(Tensor x) {
        x = relu(fc1(x));
        x = relu(fc2(x));
        x = fc3(x);
        return x;
    }
};



#endif //NETWORK_H

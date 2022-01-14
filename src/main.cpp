#define DEBUG

#include "../include/stack.h"
#include "../include/layers/chain.h"
#include "../include/layers/fc_layer.h"
#include "../include/activations.h"

#include <iostream>
#include <vector>


int main() {

    cout << "THIS IS SIGMOID: " << sigmoid_approx1(.25) << std::endl;
    /*
    Stack<float>* stack = new Stack<float>();
    
    LayerChain<float>* hidden_layers = new LayerChain<float>();

    hidden_layers->append_layers({
        new FCLayer<float, 2, 3>(sigmoid_approx1),
        new FCLayer<float, 3, 2>(sigmoid_approx1)
    });

    FCLayer<float, 3, 2> test_layer (sigmoid_approx1);

#ifdef DEBUG
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            std::cout << test_layer.getWeight(row, col) << ' ';
        }
        std::cout << std::endl;
    }
#endif
    */

    std::cout << "Stack stuff finished!" << std::endl;
}

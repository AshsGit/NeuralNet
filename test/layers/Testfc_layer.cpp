
#ifndef DEBUG
// necessary for setWeight and getWeight member functions
#define DEBUG
#endif // !DEBUG

#include "gtest/gtest.h"

#include "../../include/layers/fc_layer.h"
#include "../../include/activations.h"
#include "../../include/stack.h"

#include <cmath>        // std::abs


TEST(FC_LayerTests, random_weight_init_test) {
    const int IN = 3;
    const int OUT = 2;

    FCLayer<float, IN, OUT> layer1 (sigmoid_approx1);
    FCLayer<float, IN, OUT> layer2 (sigmoid_approx1);

    int same_init_count = 0;

    for (int row = 0; row < OUT; row++) {
        for (int col = 0; col < IN; col++) {
            auto weight1 = layer1.getWeight(row, col);
            
            EXPECT_GT(weight1, 0.0);
            EXPECT_LT(weight1, 1.0);

            auto weight2 = layer2.getWeight(row, col);

            if (std::abs(weight1 - weight2) < std::numeric_limits<float>::epsilon()) { // note, this evaluates float equality using the machine epsilon for floats.
                same_init_count++;
            }
        }
    }
    EXPECT_LT(same_init_count, 2); // ensures at most 2 duplacate inits. Fast and loose test of random weight initialization
}

TEST(FC_LayerTests, next_method) {

    auto stack = new Stack<float>();

    FCLayer<float, 4, 3> layer = sigmoid_approx1;
    layer.setInStack(stack);
    layer.setOutStack(stack);

    auto custom_weights = std::vector<std::vector<float>>{
        {1.,  2.,  3.,  4.},
        {5.,  6.,  7.,  8.},
        {9., 10., 11., 12.},
    };
    
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            auto weight = custom_weights[row][col];
            layer.setWeight(row, col, weight);
        }
    }
    
    stack->push({ 2., 4., 5., 7. });
    
    layer.next();
    
    auto out = stack->pop(3);

    auto expected_out = std::vector<float>{
        sigmoid_approx1(53), 
        sigmoid_approx1(125), 
        sigmoid_approx1(197), 
    };

    for (auto i = 0; i < 3; i++) {
        EXPECT_FLOAT_EQ(out[i], expected_out[i]);
    }
    EXPECT_TRUE(stack->isEmpty());
}

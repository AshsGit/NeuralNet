#include "../include/stack.h"
#include "../include/activations.h"

#include <random>
#include <ctime>


std::mt19937 default_mt(time(nullptr));
std::uniform_real_distribution<float> default_rand_engine(0, 1);

class FeedForwardLayer
{
private:
    Stack<float> *stack; // stack to take inputs from and push outputs to
    Activation *activation; // e.g. sigmoid, ReLu
    int in; //number of nodes in previous layer (i.e. # of inputs to pop from stack)
    int out; //number of nodes in this layer (i.e. # of outputs to push to stack)
    float *weights = this->init_weights();
    //double *biases;  not used atm

protected:
    float* init_weights() {
        // default is random between 0 and 1. Currently custom init not impl
        float** weights = new float[this->out][this->in]();

        for (int i = 0; i < this->out; i++) {
            weights[i] = default_rand_engine(default_mt);
        }
        return weights;
    }
public:
    FeedForwardLayer(
        Stack<float> *stack, 
        Activation *activation, 
        int in, 
        int out
        ) :
        activation(activation),
        stack(stack),
        in(in),
        out(out) {};

    void next() {
        // first, pull inputs from stack
        float* prev_layer_outputs = new float[this->in];

        for (int i = 0; i < this->in; i++) {
            prev_layer_outputs[i] = this->stack->pop();
        }
    }
};
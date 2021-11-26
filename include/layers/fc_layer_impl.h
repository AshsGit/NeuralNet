#pragma once

#ifndef INCLUDE_LAYERS_FC_LAYER_IMPL_H
#define INCLUDE_LAYERS_FC_LAYER_IMPL_H

#include "./fc_layer.h"

#include "../stack.h"
#include "../activations.h"
#include "../exceptions.h"

#include <random>
#include <ctime>
#include <algorithm>    // std::transform
#include <type_traits>


std::mt19937 default_mt(time(nullptr)); // TODO: check thread safety using global random generator
std::uniform_real_distribution<float> default_rand_engine (0, 1); 

float rng() {
    return default_rand_engine(default_mt);
}

template <typename _T, size_t _In, size_t _Out> 
void FCLayer<_T, _In, _Out>::init_weights() {
    // biases initialised to 0 for now. Maybe check:
    // http://karpathy.github.io/2019/04/25/recipe/
    // http://cs231n.github.io/neural-networks-2/

    for (auto i = 0; i < this->out; i++) {
        this->biases.push_back(0);
    };
};

template <class _T, size_t _In, size_t _Out>
void FCLayer<_T, _In, _Out>::init_biases() {
    // weights initialised randomly between 0 and 1. 
    // TODO: Maybe worth implementing more initialisation options for weights?

    for (int row = 0; row < this->out; row++) {
        for (int col = 0; col < this->in; col++) {
            this->weights.set(row, col, rng());
        }
    }
};

template <class _T, size_t _In, size_t _Out>
void FCLayer<_T, _In, _Out>::next() {
    // first, pull inputs from stack
    
    auto outputs = this->weights * this->in_stack->pop(this->in);
 
    for (int i = 0; i < outputs.size(); i++) {
        outputs[i] = this->activation(outputs[i] + this->biases[i]);
    }
    this->out_stack->push(outputs);
};

template <class _T, size_t _In, size_t _Out>
void FCLayer<_T, _In, _Out>::backpropogate() {

}; //TODO


template <class _T, size_t _In, size_t _Out>
void FCLayer<_T, _In, _Out>::setInStack(Stack<_T> *stack) {
    this->in_stack = stack;
};

template <class _T, size_t _In, size_t _Out>
void FCLayer<_T, _In, _Out>::setOutStack(Stack<_T> *stack) {
    this->out_stack = stack;
};

template <class _T, size_t _In, size_t _Out>
void FCLayer<_T, _In, _Out>::setBackPropStack(Stack<_T> *stack) {
    this->backprop_stack = stack;
};


#ifdef DEBUG

template <class _T, size_t _In, size_t _Out>
void FCLayer<_T, _In, _Out>::setWeight(size_t row, size_t col, _T value) {
    this->weights.set(row, col, value);
};

template <class _T, size_t _In, size_t _Out>
_T FCLayer<_T, _In, _Out>::getWeight(size_t row, size_t col) {
    return this->weights.get(row, col);
};

#endif // DEBUG

#endif
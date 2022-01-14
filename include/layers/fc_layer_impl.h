#pragma once

#ifndef INCLUDE_LAYERS_FC_LAYER_IMPL_H
#define INCLUDE_LAYERS_FC_LAYER_IMPL_H

#include "./fc_layer.h"

#include "../stack.h"
#include "../activations.h"
#include "../exceptions.h"

#include "../../external/eigen/Eigen/Dense"

#include <random>
#include <ctime>
#include <algorithm>    // std::transform
#include <type_traits>


template <class _T, size_t _In, size_t _Out>
void FCLayer<_T, _In, _Out>::next() {
    // first, pull inputs from stack
    
    Eigen::Vector<_T, _Out> outputs = this->weights * this->in_stack->pop(this->in);
 
    //for (int i = 0; i < outputs.size(); i++) {
    //    outputs[i] = this->activation(outputs[i] + this->biases[i]);
    //}
    outputs.array() += this->biases.array();
    outputs.unaryExpr(&(this->act_func.run));
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
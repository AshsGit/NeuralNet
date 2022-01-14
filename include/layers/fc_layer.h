#pragma once

#ifndef INCLUDE_LAYERS_FC_LAYER_H
#define INCLUDE_LAYERS_FC_LAYER_H

#include "./base.h"
#include "../stack.h"
#include "../activations.h"

#include "../../external/eigen/Eigen/Dense"

#include <type_traits>


template <class _T, size_t _In, size_t _Out>
class FCLayer : // Fully Connected Feed Forward Layer 
    public HiddenLayer<_T>
{

protected:
    ActivationFunc<_T> act_func;

    Eigen::Matrix<_T, _In, _Out> weights;
    Eigen::Vector<_T, _Out> biases;

public:
    FCLayer(
        ActivationFunc<_T> act_func,
        Eigen::Matrix<_T, _In, _Out> init_weights,
        Eigen::Vector<_T, _Out> init_biases
    ) :
        act_func(act_func), weights(init_weights), biases(init_biases) {};

    void next();
    void backpropogate();

    void setInStack(Stack<_T> *stack);
    void setOutStack(Stack<_T> *stack);
    void setBackPropStack(Stack<_T> *stack);

#ifdef DEBUG

    void setWeight(size_t row, size_t col, _T value);
    _T getWeight(size_t row, size_t col);

#endif // DEBUG
};


#include "./fc_layer_impl.h"

#endif
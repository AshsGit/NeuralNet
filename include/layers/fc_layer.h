#pragma once

#ifndef INCLUDE_LAYERS_FC_LAYER_H
#define INCLUDE_LAYERS_FC_LAYER_H

#include "./base.h"
#include "../stack.h"
#include "../mymath.h"
#include "../activations.h"

#include <type_traits>


template <class _T, size_t _In, size_t _Out>
class FCLayer : // Fully Connected Feed Forward Layer 
    public HiddenLayer<_T>
{
    //static_assert(std::is_arithmetic_v<_T>, "FCLayer not defined for non-arithmetic types");

protected:
    Activation<_T> activation;

    const size_t in = _In;   //number of nodes in previous layer (i.e. # of inputs to pop from stack)
    const size_t out = _Out; //number of nodes in this layer (i.e. # of outputs to push to stack)
    
    StaticMatrix2D<_T, _In, _Out> weights;
    vector<_T> biases;

    void init_weights();
    void init_biases();

public:
    FCLayer(Activation<_T> activation) : 
        activation(activation) 
        {   
            this->init_weights(); 
            this->init_biases(); 
        };

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
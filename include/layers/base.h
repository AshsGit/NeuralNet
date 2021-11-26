#pragma once

#ifndef INCLUDE_LAYERS_BASE_H
#define INCLUDE_LAYERS_BASE_H

#include "../stack.h"

#include <vector>


template <class _T>
class HiddenLayer
{
protected:
    Stack<_T> *in_stack; // data stack used for layer input
    Stack<_T> *out_stack; // data stack used for layer output
    Stack<_T> *backprop_stack; // stack used by each layer in network during backpropagation
    size_t in;   // number of layer inputs 
    size_t out; // number of layer outputs

public:
    virtual void next() = 0;
    virtual void backpropogate() = 0;

    virtual void setInStack(Stack<_T> *stack) = 0;
    virtual void setOutStack(Stack<_T> *stack) = 0;
    virtual void setBackPropStack(Stack<_T> *stack) = 0;
    size_t getIn() const {return this->in;}
    size_t getOut() const {return this->out;}
};


template <class _T, size_t _In, size_t _Out>
class ANN
{
    const size_t in = _In;   // number of network inputs 
    const size_t out = _Out; // number of network outputs
    HiddenLayer<_T>* hiddenlayer;

public:
    ANN(HiddenLayer<_T>* hiddenlayer) : hiddenlayer(hiddenlayer) {};

    std::vector<_T> run(std::vector<_T> in);
    void backpropogate(std::vector<_T> errors);

    // serialize();
    // deserialize();
};


// template <class _T, size_t _In, size_t _Out>
// class HiddenLayer : public HiddenLayer2
// {
// protected:
//     Stack<_T> *stack; // data stack used by each layer in network
//     const size_t in = _In;   // number network of inputs 
//     const size_t out = _Out; // number network of outputs

// public:
//     void next();
//     void backpropogate();

//     void setStack(Stack<_T> *stack) = {this->stack = stack;}
// };


#endif // !INCLUDE_LAYERS_BASE_H

#pragma once

#ifndef INCLUDE_LAYERS_CHAIN_H
#define INCLUDE_LAYERS_CHAIN_H


#include "./base.h"

template <class _T>
class LayerChain : 
    public HiddenLayer<_T>
{
protected:
    Stack<_T> *stack; // data stack used by each layer in network

    vector<HiddenLayer<_T>*> chained_layers = {}; 
public:

    void next();
    void backpropogate();

    void append_layer(HiddenLayer<_T> *layer);
    void append_layers(vector<HiddenLayer<_T>*> layers);
    void setStack(Stack<_T> *stack);
};

#include "chain_impl.h"

#endif // !INCLUDE_LAYERS_CHAIN_H



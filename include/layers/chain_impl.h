#pragma once

#ifndef INCLUDE_LAYERS_CHAIN_IMPL_H
#define INCLUDE_LAYERS_CHAIN_IMPL_H


#include "./chain.h"
#include "./base.h"

template <class _T>
void LayerChain<_T>::next() {
    for (auto layer : this->chained_layers) {
        layer->next();
    }
};

template <class _T>
void LayerChain<_T>::backpropogate() {}; // TODO

template <class _T>
void LayerChain<_T>::append_layer(HiddenLayer<_T>* layer) {
    if (this->chained_layers.empty()) {
        this->in = layer->getIn();
    }
    this->out = layer->getOut();
    this->chained_layers.push_back(layer); // TODO sus push_back
};

template <class _T>
void LayerChain<_T>::append_layers(vector<HiddenLayer<_T>*> layers) {
    for (auto layer : layers) {
        this->append_layer(layer);
    }
};

template <class _T>
void LayerChain<_T>::setStack(Stack<_T> *stack) {
    for (auto layer : this->chained_layers) {
        layer->setStack(stack);
    }
    this->stack = stack;
};


#endif // !INCLUDE_LAYERS_CHAIN_IMPL_H



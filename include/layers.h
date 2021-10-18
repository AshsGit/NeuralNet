#pragma once

#ifndef FEED_FORWARD_LAYER_H
#define FEED_FORWARD_LAYER_H

#include "./stack.h"
#include "./activations.h"

class FeedForwardLayer
{
public:
    FeedForwardLayer(Stack<float> *stack, Activation *activation, int in, int out);
    void next();
};

#endif
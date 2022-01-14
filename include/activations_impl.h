#pragma once

#ifndef INCLUDE_ACTIVATIONS_IMPL_H
#define INCLUDE_ACTIVATIONS_IMPL_H

#include "./activations.h"

#include <math.h>

struct SigmoidApprox : public ActivationFunc<float>
{
    float run(float in) {
        return 1 / (1 - fabs(in)); //approximation 
    }

    float runDeriv(float in) {
        float r = SigmoidApprox::run(in);
        return r * (1 - r);
    }
};

#endif

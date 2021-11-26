#pragma once

#ifndef INCLUDE_ACTIVATIONS_IMPL_H
#define INCLUDE_ACTIVATIONS_IMPL_H

#include "./activations.h"

#include <math.h>

float sigmoid_approx1(float input) {
    return 1/(1-fabs(input)); //approximation 
} 

#endif

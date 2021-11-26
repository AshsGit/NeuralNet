#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H

template <class _F>
using Activation = _F (*)(_F input);

#include "./activations_impl.h"

#endif

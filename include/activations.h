#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H

template <class _T>
struct ActivationFunc
{
	_T run(_T in);
	_T runDeriv(_T in);
};

#include "./activations_impl.h"

#endif

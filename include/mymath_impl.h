#pragma once

#ifndef INCLUDE_MYMATH_IMPL_H
#define INCLUDE_MYMATH_IMPL_H


#include "../include/mymath.h"

#include <numeric> // std::inner_product
#include <cassert>

template<class _T, size_t _W, size_t _H> 
StaticMatrix2D<_T, _W, _H>::StaticMatrix2D(void) {
    this->data = vector<_T>(this->height * this->stride);
}

template<class _T, size_t _W, size_t _H> 
void StaticMatrix2D<_T, _W, _H>::set(size_t row, size_t col, _T value) {
    assert(col < this->stride); //needs to be asserted as otherwise no overflow will occur since this->data is continuous. Thus, the error will be silent
    this->data[row*this->stride + col] = value;
}

template<class _T, size_t _W, size_t _H> 
_T StaticMatrix2D<_T, _W, _H>::get(size_t row, size_t col) {
    assert(col < this->stride); //needs to be asserted as otherwise no overflow will occur since this->data is continuous. Thus, the error will be silent
    return this->data[row*this->stride + col];
}

using std::vector;

template<class _T, size_t _W, size_t _H>
vector<_T> StaticMatrix2D<_T, _W, _H>::operator*(const vector<_T>& vec) {
    vector<_T> out (_H);
    for (size_t row = 0; row < _H; row++) {
        out[row] = std::inner_product(
            vec.begin(), 
            vec.end(),
            this->data.begin() + row*this->stride,
            0.0);
    }
    return out;
}


#endif
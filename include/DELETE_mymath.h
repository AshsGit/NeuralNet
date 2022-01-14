#pragma once

#ifndef INCLUDE_MYMATH_H
#define INCLUDE_MYMATH_H

#include <vector>

using std::vector;

template<class _Type, size_t _Width, size_t _Height>
struct StaticMatrix2D
{
    const size_t height = (size_t) _Height;
    const size_t stride = (size_t) _Width;
    vector<_Type> data; //= new _Type[height * _Width]; // should probably not use vectors as I believe they are implemented with linked lists

    void set(size_t row, size_t col, _Type value);
    _Type get(size_t row, size_t col);
    
    StaticMatrix2D(void);
    vector<_Type> operator*(const vector<_Type>& vec); // matrix-vector multiplication
};


#include "./mymath_impl.h"

#endif // INCLUDE_MYMATH_H
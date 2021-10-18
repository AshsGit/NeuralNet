#include "../include/mymath.h"

#include <numeric> // std::inner_product

template<class _T, size_t _W, size_t _H> 
StaticMatrix2D<_T, _W, _H>::StaticMatrix2D(void) {
    this->data.reserve(this->height * this->stride);
    
}

template<class _T, size_t _W, size_t _H> 
void StaticMatrix2D<_T, _W, _H>::set(size_t row, size_t col, _T value) {
    this->data[row*this->stride + col] = value;
}

template<class _T, size_t _W, size_t _H> 
_T StaticMatrix2D<_T, _W, _H>::get(size_t row, size_t col) {
    return this->data[row*this->stride + col];
}

using std::vector;

template<class _T, size_t _W, size_t _H>
vector<_T> StaticMatrix2D<_T, _W, _H>::operator*(const vector<_T>& vec) {
    vector<_T> out (_H);
    for (size_t row = 0; row < _H; row++) {
        out[row_i] = std::inner_product(
            vec.begin(), 
            vec.end(),
            this->data.begin() + row*this->stride,
            0.0);
    }
    return out;
}
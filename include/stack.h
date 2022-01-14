#pragma once

#ifndef INCLUDE_STACK_H
#define INCLUDE_STACK_H

#include <exception>
#include <string>
#include <vector>

#include "../../external/eigen/Eigen/Dense"


using namespace std;

//exceptions
class StackException : public std::exception {};
class StackPopOnEmpty : public StackException {};
class StackIrrecoverableDataLoss : 
    public StackPopOnEmpty {};


template<class _T>
class Stack {
private:
    struct Node;
    Node* head = nullptr;
public:
    Stack<_T>() = default;

    void push(T payload);
    T pop(void);

    template<size_t _S>
    void push(Eigen::Vector<_T, _S> items); // items are pushed in reverse-order (this is done to preserve order between push many and pop many)
    
    template<size_t _S>
    Eigen::Vector<_T> pop(); // vector values are arranged in pop order
    
    bool isEmpty(void);
};

#include "./stack_impl.h"

#endif 
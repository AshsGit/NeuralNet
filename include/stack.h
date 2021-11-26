#pragma once

#ifndef INCLUDE_STACK_H
#define INCLUDE_STACK_H

#include <exception>
#include <string>
#include <vector>

using namespace std;

//exceptions
class StackException : public std::exception {};
class StackPopOnEmpty : public StackException {};
class StackIrrecoverableDataLoss : 
    public StackPopOnEmpty {};


//classes
// template<class T>
// struct Stack {
//     virtual void push(T payload) = 0;
//     virtual T pop(void) = 0;
//     virtual bool isEmpty(void) = 0;
// };

template<class T>
class Stack {
private:
    struct Node;
    Node* head = nullptr;
public:
    Stack<T>() = default;
    void push(T payload);
    T pop(void);
    void push(vector<T> items); // items are pushed in reverse-order (this is done to preserve order between push many and pop many)
    vector<T> pop(unsigned int n); // vector values are arranged in pop order
    bool isEmpty(void);
};

#include "./stack_impl.h"

#endif 
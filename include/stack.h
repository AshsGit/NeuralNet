#pragma once
#ifndef STACK_H
#define STACK_H

#include <exception>
#include <string>

using namespace std;

//exceptions
class StackException : public std::exception {};
class StackPopOnEmpty : public StackException {};


//classes
template<typename T>
struct Stack {
    virtual void push(T payload) = 0;
    virtual T pop(void) = 0;
    virtual bool isEmpty(void) = 0;
};


namespace linked {
    template<typename T>
    class Stack : public ::Stack<T> {
    private:
        struct Node;
        Node* head = nullptr;
    public:
        Stack<T>() = default;
        void push(T payload);
        T pop(void);
        bool isEmpty(void);
    };
}

#endif 
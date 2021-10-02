#pragma once
#ifndef STACK_H
#define STACK_H

#include <exception>
#include <string>

#include "config.h"

using namespace std;

//exceptions
class StackException : public std::exception {};
class StackPopOnEmpty : public StackException {};


//classes
struct Stack {
    virtual void push(config::weight_t payload) = 0;
    virtual config::weight_t pop(void) = 0;
    virtual bool isEmpty(void) = 0;
};


namespace linked {
    class Stack : public ::Stack {
    private:
        struct Node;
        Node* head = nullptr;
    public:
        Stack() = default;
        void push(config::weight_t payload);
        config::weight_t pop(void);
        bool isEmpty(void);
    };
}

#endif 
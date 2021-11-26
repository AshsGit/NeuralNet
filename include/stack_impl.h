#pragma once

#ifndef INCLUDE_STACK_IMPL_H
#define INCLUDE_STACK_IMPL_H

#include "./stack.h"

#include <vector>

using namespace std;

template<typename T>
struct Stack<T>::Node {
    T payload;
    Node* prev = nullptr;
    Node(T payload, Node* prev)
        : payload(payload)
        , prev(prev) {};
};

template<typename T>
void Stack<T>::push(T payload) {
    head = new Node(payload, head); 
}

template<typename T>
T Stack<T>::pop(void) {
    if (head == nullptr) throw StackPopOnEmpty();
    else {
        T payload = head->payload;
        Node* prev = head->prev;
        delete head;
        head = prev;
        return payload;
    }
}

template<typename T>
void Stack<T>::push(vector<T> items) {
    for (int i = items.size()-1; i >=0; i--) {
        this->push(items[i]);
    }
}

template<typename T>
vector<T> Stack<T>::pop(unsigned int n) {
    
    vector<T> vals (n);
    try
    {
        for (int i = 0; i < n; i++) {
            vals[i] = this->pop();
        }
    }
    catch(const StackPopOnEmpty& e)
    {
        throw StackIrrecoverableDataLoss();
    }
    return vals;
}

template<typename T>
bool Stack<T>::isEmpty(void) {
    return head == nullptr;
}


#endif
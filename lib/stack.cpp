#include "../include/stack.h"

using namespace std;

template<typename T>
struct linked::Stack<T>::Node {
    T payload;
    Node* prev = nullptr;
    Node(T payload, Node* prev)
        : payload(payload)
        , prev(prev) {};
};

template<typename T>
void linked::Stack<T>::push(T payload) {
    head = new Node(payload, head); 
}

template<typename T>
T linked::Stack<T>::pop(void) {
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
bool linked::Stack<T>::isEmpty(void) {
    return head == nullptr;
}

#include "../include/stack.h"

using namespace std;


struct linked::Stack::Node {
    config::weight_t payload;
    Node* prev = nullptr;
    Node(config::weight_t payload, Node* prev)
        : payload(payload)
        , prev(prev) {};
};

void linked::Stack::push(config::weight_t payload) {
    head = new Node(payload, head); 
}

config::weight_t linked::Stack::pop(void) {
    if (head == nullptr) throw StackPopOnEmpty();
    else {
        config::weight_t payload = head->payload;
        Node* prev = head->prev;
        delete head;
        head = prev;
        return payload;
    }
}

bool linked::Stack::isEmpty(void) {
    return head == nullptr;
}

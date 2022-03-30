#include "queue/queue.h"
#include "SLL/SLL.cpp"

template <typename type>
QUEUE<type>::QUEUE()
    : list{} {}

template <typename type>
void QUEUE<type>::clear() {
    list.clear();
}

template <typename type>
bool QUEUE<type>::isEmpty() {
    return list.isEmpty();
}

template <typename type>
void QUEUE<type>::enqueue(type value) {
    list.addToHead(value);
}

template <typename type>
type QUEUE<type>::dequeue() {
    return list.deleteFromTail();
}

template <typename type>
type QUEUE<type>::first() {
    if(list.isEmpty()) throw std::runtime_error("list is empty");
    return list.head->info;
}
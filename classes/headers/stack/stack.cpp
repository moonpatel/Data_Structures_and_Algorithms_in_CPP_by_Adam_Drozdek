#include <vector>

#include "stack.h"

template <typename type>
STACK<type>::STACK()
    : pool{} {}

template <typename type>
void STACK<type>::push(type object) {
    pool.push_back(object);
}

template <typename type>
type STACK<type>::pop() {
    pool.pop_back();
}

template <typename type>
int STACK<type>::size() {
    return pool.size();
}

template <typename type>
bool STACK<type>::isEmpty() {
    return pool.size()==0;
}

template <typename type>
type STACK<type>::top() {
    return pool[this->size()-1];
}
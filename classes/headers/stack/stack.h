#ifndef _STACK_H_
#define _STACK_H_

template <typename type>
class STACK {
private:
    vector<type> pool;
public:
    STACK();    // Default constructor
    void push(type object);     // push object on top of the stack
    type pop();                 // remove the top element of the stack
    int size();                 // return the size of the stack
    bool isEmpty();             // return true if the stack is empty else false
    type top();                 // return  the top element of the stack without removing it
};

#endif
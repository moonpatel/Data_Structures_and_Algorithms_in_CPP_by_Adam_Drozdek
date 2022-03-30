#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "SLL/SLL.h"

template <typename type>
class QUEUE {
private:
    SLL<type> list;
public:
    QUEUE();
    void clear();
    bool isEmpty();
    void enqueue(type value);
    type dequeue();
    type first();
};

#endif
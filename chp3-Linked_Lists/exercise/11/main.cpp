#include <iostream>

#include "../../singly_linked_list/SLL.h"
#include "../../singly_linked_list/SLL.cpp"


using namespace std;


int main() {
    SLL<int> list;

    list.addToTail(2);
    list.addToTail(4);
    list.addToTail(6);
    list.addToTail(9);

    cout << "Before reversing: ";
    list.print();

    list.reverse();

    cout << "After reversing: ";
    list.print();

    return 0;
}

// template <typename type>
// void SLL<type>::reverse() {
//     this->reverseSubList(nullptr,this->head);
//     SLLNode<type>* temp = this->head;
//     this->head = this->tail;
//     this->tail = temp;
// }

// template <typename type>
// void SLL<type>::reverseSubList(SLLNode<type>* prev, SLLNode<type>* first) {
//     if(first->next == nullptr)
//         first->next=prev;
//     else {
//         reverseSubList(first,first->next);
//         first->next=prev;
//     }
// }
#include <iostream>
#include <vector>

#include "SLL.h"
#include "SLL.cpp"


using namespace std;


int main() {
    SLL<string> list;
    list.addToTail("one");
    list.addToTail("two");
    list.addToTail("four");
    list.addToTail("six");
    list.addToTail("seven");
    list.addToTail("eight");
    list.addToTail("nine");
    list.addToTail("ten");
    SLLNode<string>* ptr;
    ptr = list.head->next->next;
    cout << "Before inserting: " << "\n";
    list.print();
    list.insertAt("three",ptr);
    cout << "Before inserting: " << "\n";
    list.print();
    list.insertAfter("five",ptr);
    cout << "After inserting: " << "\n";
    list.print();

    return 0;
}
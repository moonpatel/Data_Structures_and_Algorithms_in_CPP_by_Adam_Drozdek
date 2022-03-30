#include <iostream>
#include <string>

#include "SLL.h"
#include "SLL.cpp"


using namespace std;


int main() {
    SLL<string> list1{},list2{};
    list1.addToTail("one");
    list1.addToTail("two");
    list1.addToTail("three");

    list2.addToTail("four");
    list2.addToTail("five");

    list1.append(list2);
    list1.print();
    list2.print();


    return 0;
}
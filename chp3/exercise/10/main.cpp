#include <iostream>
#include <iomanip>

#include "SLL.h"
#include "SLL.cpp"


using namespace std;


int main() {
    SLL<int> list1;
    SLL<int> list2;

    list1.addToHead(2);
    list1.addToHead(4);
    list1.addToHead(6);
    list1.addToHead(9);

    list2.addToHead(2);
    list2.addToHead(4);
    list2.addToHead(6);
    list2.addToHead(9);

    cout << "Are the lists same? " << "\n" << boolalpha << (list1==list2) << "\n";

    return 0;
}
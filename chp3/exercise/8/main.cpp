#include <iostream>
#include "../../singly_linked_list/SLL.h"
#include "../../singly_linked_list/SLL.cpp"


using namespace std;


int main() {
    SLL<int> numbers;
    numbers.addToTail(1);
    numbers.addToTail(3);
    numbers.addToTail(5);
    numbers.addToTail(7);
    numbers.addToTail(8);

    int i=numbers.size()-1;
    while(i>=0) {
        numbers.deleteNodeAt(numbers[i]-1);
        i--;
    }

    numbers.print();

    return 0;
}
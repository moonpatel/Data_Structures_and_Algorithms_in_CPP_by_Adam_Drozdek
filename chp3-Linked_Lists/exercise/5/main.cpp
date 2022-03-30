#include <iostream>
#include "../../singly_linked_list/SLL.h"
#include "../../singly_linked_list/SLL.cpp"


using namespace std;


int main() {
    SLL<int> list;
    for(int i=0; i<10; i++) {
        list.addToTail(i);
    }

    cout << "Enter the index of element you want to access: ";
    int num;
    cin >> num;
try {
    cout << "The element at index " << num << " is " << list[num] << "\n";
}
catch (runtime_error &e) {
    cout << e.what() << "\n";
    return 1;
}


    return 0;
}
#include <iostream>
#include "DLL.h"


using namespace std;


int main() {
    DLL list;
    cout << list.isEmpty() << endl;
    list.addToTail(7);
    list.addToTail(0);
    list.addToTail(9);
    list.addToTail(6);
    list.addToTail(6);
    list.addToTail(5);
    list.addToTail(6);

    cout << "List is empty: ";
    cout << list.isEmpty() << endl;
    list.deleteNode(9);
    list.deleteNode(5);
    list.deleteNode(7);
    list.deleteNodes(6);
    list.deleteNode(0);

    cout << "List is empty: ";
    cout << list.isEmpty() << endl;


    int num;

    return 0;
}
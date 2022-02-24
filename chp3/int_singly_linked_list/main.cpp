#include <iostream>
#include "IntSLL.h"


using namespace std;


int main() {
    IntSLL list;
    list.addToTail(7);
    list.addToTail(0);
    list.addToTail(9);
    list.addToTail(6);
    list.addToTail(8);
    list.addToTail(6);
    list.addToTail(6);
    list.addToTail(9);
    list.addToTail(8);
    list.addToTail(2);

    cout << "Size of the list is " << list.size() << endl;
    list.print();
    cout << endl;


    // list.deleteNode(5);
    // cout << "After deleting 5: " << endl;
    // list.print();
    // cout << endl;

    // list.deleteNode(9);
    // cout << "After deleting 9: " << endl;
    // list.print();
    // cout << endl;

    // list.deleteNodes(6);
    // cout << "After deleting all 6: " << endl;
    // list.print();
    // cout << endl;

    // list.deleteNodes(7);
    // cout << "After deleting all 7: " << endl;
    // list.print();
    // cout << endl;

    // cout << "Add 5 to head: " << endl;
    // list = 5 + list;
    // list.print();

    // cout << "Add 5 to tail: " << endl;
    // list = list + 5;
    // list.print();

    for(int i=0; i<list.size(); i++) {
        list[i]=i;
    }

    cout << endl << "After modifying list: " << endl;
    list.print();

    list[413] = 444;

    cout << endl << "After modifying list: " << endl;
    list.print();


    return 0;
}
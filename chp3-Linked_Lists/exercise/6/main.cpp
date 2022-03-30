#include <iostream>
#include "../../singly_linked_list/SLL.h"
#include "../../singly_linked_list/SLL.cpp"


using namespace std;


int main() {
    SLL<char> list{};
    for(char ch='A'; ch<='E'; ch++) {
        list.addToTail(ch);
    }

    list.print();

    SLL<int> indices{};
    indices.addToTail(2);
    indices.addToTail(4);
    indices.addToTail(8);

    for(int i=indices.size()-1; i>=0; i--) {
        if(indices[i]-1>=list.size())
            continue;

        list.deleteNodeAt(indices[i]-1);
    }

    list.print();


    return 0;
}
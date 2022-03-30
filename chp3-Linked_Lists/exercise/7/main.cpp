#include <iostream>
#include "../../singly_linked_list/SLL.h"
#include "../../singly_linked_list/SLL.cpp"


using namespace std;


int main() {
    SLL<char> alphabets;
    alphabets.addToTail('A');
    alphabets.addToTail('B');
    alphabets.addToTail('C');
    alphabets.addToTail('D');
    alphabets.addToTail('E');

    SLL<int> indices1{};
    indices1.addToTail(2);
    indices1.addToTail(4);
    indices1.addToTail(8);

    SLL<int> indices2{};
    indices2.addToTail(2);
    indices2.addToTail(5);

    indices1.merge(indices2);

    if(indices1[indices1.size()-1] > 0 && indices1[indices1.size()-1] <= alphabets.size() )
        alphabets.deleteNodeAt(indices1[indices1.size()-1]-1);

    for(int i=indices1.size()-2; i>=0; i--) {
        
        if(indices1[i]!=indices1[i+1])
            alphabets.deleteNodeAt(indices1[i]-1);
    }

    alphabets.print();

    return 0;
}
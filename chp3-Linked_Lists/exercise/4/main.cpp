#include <iostream>
#include "../../singly_linked_list/SLL.h"
#include "../../singly_linked_list/SLL.cpp"


using namespace std;

template <typename type>
SLL<type> merge(SLL<type> &list1, SLL<type> &list2) {
    int size1=list1.size();
    int size2=list2.size();
    int i{0},j{0};

    SLLNode<type>* ptr1;
    ptr1 = list1.head;
    SLLNode<type>* ptr2;
    ptr2 = list2.head;

    SLL<type> list{};

    while(true) {
        if(ptr1->info < ptr2->info) {
            list.addToTail(ptr1->info);
            ptr1=ptr1->next;
            i++;
            if(i>=size1) {
                while(ptr2!=nullptr) {
                    list.addToTail(ptr2->info);
                    ptr2 = ptr2->next;
                }
                return list;
            }
        }
        else {
            list.addToTail(ptr2->info);
            ptr2=ptr2->next;
            j++;
            if(j>=size2) {
                while(ptr1!=nullptr) {
                    list.addToTail(ptr1->info);
                    ptr1 = ptr1->next;
                }
                return list;
            }
        }
    }
}

int main() {
    SLL<int> list1{},list2{};

    list1.addToTail(3);
    list1.addToTail(35);
    list1.addToTail(46);
    list1.addToTail(61);
    list1.addToTail(80);

    list2.addToTail(4);
    list2.addToTail(25);
    list2.addToTail(44);
    list2.addToTail(73);
    list2.addToTail(91);

    list1.print();
    list2.print();

    cout << endl << endl;
    cout << "Merging lists" << endl;

    (merge(list1,list2)).print();


    return 0;
}
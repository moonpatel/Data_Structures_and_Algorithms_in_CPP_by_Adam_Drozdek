#include <iostream>
#include <iomanip>
#include "IntSLL.h"


// IntSLLNode class member functions
IntSLLNode::IntSLLNode()                       // Default constructor
    : next{nullptr} {}

IntSLLNode::IntSLLNode(int el, IntSLLNode *ptr)    // Two args constructor
    : info{el}, next{ptr} {}

// returns the size of the list
int IntSLL::size() {
    return list_size;
}


// IntSLL class member functions
IntSLL::IntSLL()              // Default constructor
    : head{nullptr}, tail{nullptr}, list_size{0} {}           // head and tail points to null


// Destructor for a linked list
IntSLL::~IntSLL() {
// Loop through the linked list deleting one by one until list becomes empty

    for(IntSLLNode *p; !isEmpty(); ) 
    {
        p = head->next;     // asssign the address of 2nd node to p
        delete head;        // delete first node
        head = p;           // assign the address of second node to head
    }
}

// function to check whether list is empty or not
bool IntSLL::isEmpty() {
    return head == nullptr;       // returns true if head points to a nul pointer
}

// add a node to the head of the list
// STEPS:
// 1. create a new node with a value pointing to first node
// 2. assign this node to head
void IntSLL::addToHead(int num) {
    // initialize a node with value pointing to the head of the list 
    // and assign it to the head pointer
    head = new IntSLLNode(num,head);
    if(tail==0)         // assign head to tail if previously
        tail = head;    // the list was empty

    list_size++;
}

// add a node to the tail of the list
// STEPS:
// 1. create a new node with a value and pointing to nullptr
// 2. assign this to the next member of the last pointer
// 3. make tail point to this new pointer
void IntSLL::addToTail(int num) {
    list_size++;
    if(tail!=0) {   // if list is not empty
    // initialize a new node with value num and make it pointed by
    // the tail of the list
        tail->next = new IntSLLNode(num);
        tail = tail->next;    // update the tail pointer
    }
    else {
        tail = new IntSLLNode(num); // assign the new node to tail
        head = tail;        // head and tail points to the single node
    }
}

// delete the head node and return its info
int IntSLL::deleteFromHead() {
    if(this->size()==0) throw std::runtime_error("Cannot delete from an empty list");

    list_size--;
    int num = head->info;      // store head's info in num
    IntSLLNode *temp = head;    // pointer to head

    if(head==tail)
        head = tail = {nullptr};    // if only one node in list
                                    // null both tail and head
    else
        head = head->next;      // else point to next node
        delete temp;            // delete the first node
        return num;             // return head's info
}

// delete the tail node and return its info
int IntSLL::deleteFromTail() {
    if(this->size()==0) throw std::runtime_error("Cannot delete from an empty list");

    list_size--;

    int num = tail->info;   // store the info of the node which is deleted

    IntSLLNode *ptr = head; // start from head

    if(head == tail) {          // if there is only one node 
        delete head;
        tail = head = nullptr;

        return num;
    }
    // loop through the list till ptr reahes second last node.
    for( ; ptr->next->next != nullptr; ptr = ptr->next);

    delete tail;                // deletes the last node
    tail = ptr;                 // make the second last node the new tail
    tail->next = nullptr;       // null out last node next member

    return num;      // returns the deleted node info
}

// deletes the node with info value num
void IntSLL::deleteNode(int num) {
    if(head!=0) {
        if(head == tail && head->info==num) {   // if only one node is in the list
            delete head;                // delete the node
            head = tail = nullptr;      // set head and tail to nullptr
            list_size--;
        }
        else if(head->info==num) {
            IntSLLNode *temp = head;    // if more than one node but head's info is equal to num
            head = head->next;      // update head
            delete temp;        // delete the old head
            list_size--;
        }
        else {          // more than one node and head's info not equal to num
            IntSLLNode *prev, *curr;
            prev = head;            // set prev to first node
            curr = head->next;      // set curr to second node
            for(; curr!=nullptr; prev=curr,curr=curr->next) {
                if(curr->info==num) {
                    if(curr==tail) {        // if tail is to be deleted
                        this->deleteFromTail();
                    }
                    else {          // if a node between head and tail is to be deleted
                        prev->next=curr->next;
                        delete curr;
                        list_size--;

                    }
                }
            }
        }
    }
}

// deletes all the nodes having value of info as num
void IntSLL::deleteNodes(int num) {
    while(isInList(num)) {      // true till num is in the list
        this->deleteNode(num);  // delete num from the list one by one
    }
}

// return true if num is in the list.
// This function loops through the list and matches the number one by one with
// node's info and returns true if match is found.
bool IntSLL::isInList(int num) const {
    if(head!=nullptr) {
    IntSLLNode *ptr = head;     // start from the head

    if(head==tail) 
        return ptr->info == num; // executes if only one node
    else
        for( ; ptr!=nullptr; ptr=ptr->next)
            if(ptr->info==num) return true;     // return true if match found
    
    return false;   // return false if no matches found
    }
    else return false;
}

// prints the elements of the list line by line
void IntSLL::print() const {
    int i=1;
    IntSLLNode *ptr = head;

    if(ptr==nullptr) return;

    do {
        std::cout << std::setw(2) << std::right << i << "). " << ptr->info << std::endl;
        ptr = ptr->next;
        i++;
    } while(ptr != nullptr);

    delete ptr;
}

// add num to tail
IntSLL &operator+(IntSLL &list, int num) {
    list.addToTail(num);
    return list;
}

// add num to head
IntSLL &operator+(int num, IntSLL &list) {
    list.addToHead(num);
    return list;
}

// access list elements through their index
int &IntSLL::operator[](int index) {
    if(index>=list_size || index<0)     // check if index is in the range[0:list_size)
        throw std::runtime_error("list index out of bounds");

    IntSLLNode *ptr = head;

    // loop through till the ptr points to the list[index] node
    for(int i=0; i!=index; i++) {
        ptr = ptr->next;
    }

    return ptr->info;
}
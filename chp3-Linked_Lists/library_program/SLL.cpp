#include <iostream>
#include <iomanip>
#include "SLL.h"


// SLLNode class member functions
template <typename type>
SLLNode<type>::SLLNode()                       // Default constructor
    : info{}, next{nullptr} {}


template <typename type>
SLLNode<type>::SLLNode(type el, SLLNode *ptr)    // Two args constructor
    : info{el}, next{ptr} {}


// SLL class member functions
template <typename type>
SLL<type>::SLL()              // Default constructor
    : head{nullptr}, tail{nullptr}, sizeOfList{0} {}           // head and tail points to null


// Destructor for a linked list
template <typename type>
SLL<type>::~SLL() {
// Loop through the linked list deleting one by one until list becomes empty

    for(SLLNode<type> *p; !isEmpty(); ) 
    {
        p = head->next;     // asssign the address of 2nd node to p
        delete head;        // delete first node
        head = p;           // assign the address of second node to head
    }
}


// returns the size of the list
template <typename type>
int SLL<type>::size() const {
    return sizeOfList;
}


// function to check whether list is empty or not
template <typename type>
bool SLL<type>::isEmpty() const {
    return head == nullptr;       // returns true if head points to a nul pointer
}


// add a node to the head of the list
// STEPS:
// 1. create a new node with a value pointing to first node
// 2. assign this node to head
template <typename type>
void SLL<type>::addToHead(type data) {
    // initialize a node with value pointing to the head of the list 
    // and assign it to the head pointer
    head = new SLLNode<type>(data,head);
    if(tail==0)         // assign head to tail if previously
        tail = head;    // the list was empty

    sizeOfList++;
}


// add a node to the tail of the list
// STEPS:
// 1. create a new node with a value and pointing to nullptr
// 2. assign this to the next member of the last pointer
// 3. make tail point to this new pointer
template <typename type>
void SLL<type>::addToTail(type data) {
    if(tail!=0) {   // if list is not empty
    // initialize a new node with value num and make it pointed by
    // the tail of the list
        tail->next = new SLLNode<type>(data);
        tail = tail->next;    // update the tail pointer
    }
    else {
        tail = new SLLNode<type>(data); // assign the new node to tail
        head = tail;        // head and tail points to the single node
    }

    sizeOfList++;
}


// delete the head node and return its info
template <typename type>
type SLL<type>::deleteFromHead() {
    type data = head->info;      // store head's info in num
    SLLNode<type> *temp = head;    // pointer to head

    if(head==tail)
        head = tail = {nullptr};    // if only one node in list 
                                    // null out both tail and head
    else
        head = head->next;      // else point to next node
    
    delete temp;            // delete the first node
    sizeOfList--;

    return data;             // return head's info
}


// delete the tail node and return its info
template <typename type>
type SLL<type>::deleteFromTail() {
    type data = tail->info;   // store the info of the node which is deleted

    SLLNode<type> *ptr = head; // start from head

    if(head == tail) {          // if there is only one node 
        delete head;
        tail = head = nullptr;

        sizeOfList--;

        return data;
    }
    // loop through the list till ptr reahes second last node.
    for( ; ptr->next->next != nullptr; ptr = ptr->next);

    delete tail;                // deletes the last node
    tail = ptr;                 // make the second last node the new tail
    tail->next = nullptr;       // null out last node next member

    sizeOfList--;

    return data;      // returns the deleted node info
}


// deletes the node with info value num
template <typename type>
void SLL<type>::deleteNode(type data) {
    if(head!=0) {
        if(head == tail && head->info==data) {   // if only one node is in the list
            delete head;                // delete the node
            head = tail = nullptr;      // set head and tail to nullptr

            sizeOfList--;
        }
        else if(head->info==data) {
            SLLNode<type> *temp = head;    // if more than one node but head's info is equal to num
            head = head->next;      // update head;
            delete temp;        // delete the old head;

            sizeOfList--;
        }
        else {          // more than one node and head's info not equal to num
            SLLNode<type> *prev, *curr;
            prev = head;            // set prev to first node
            curr = head->next;      // set curr to second node
            for(; curr!=nullptr; prev=curr,curr=curr->next) {
                if(curr->info==data) {
                    if(curr==tail) {        // execute if tail is to be deleted
                        this->deleteFromTail();
                    }
                    else {          // execute if a node between head and tail is to be deleted
                        prev->next=curr->next;
                        delete curr;

                        sizeOfList--;
                    }
                }
            }
        }
    }
}


// deletes all the nodes having value of info as num
template <typename type>
void SLL<type>::deleteNodes(type data) {
    while(isInList(data)) {      // true till num is in the list
        this->deleteNode(data);  // delete num from the list one by one
    }
}


// return true if num is in the list.
// This function loops through the list and matches the number one by one with
// node's info and returns true if match is found.
template <typename type>
bool SLL<type>::isInList(type data) const {
    if(head!=nullptr) {
    SLLNode<type> *ptr = head;     // start from the head

    if(head==tail) 
        return ptr->info == data; // executes if only one node
    else
        for( ; ptr!=nullptr; ptr=ptr->next)
            if(ptr->info==data) return true;     // return true if match found
    
    return false;   // return false if no matches found
    }
    else
        return false;
}


// prints the elements of the list line by line
template <typename type>
void SLL<type>::print() const {
    SLLNode<type> *ptr = head;
    for(int i=0; i<this->size(); i++) {
        std::cout << ptr->info << std::endl;
        ptr = ptr->next;
    }
}
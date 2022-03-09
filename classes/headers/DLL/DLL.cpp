#include <iostream>
#include "DLL.h"

// Default constructor for a node
DLLNode::DLLNode() : info{}, next{nullptr}, prev{nullptr} {}

// Constructor for a node
DLLNode::DLLNode(int num) : info{num}, next{nullptr}, prev{nullptr} {}

// Default constructor for a list
DLL::DLL() : head{nullptr}, tail{nullptr} {}

// returns true if list is empty
bool DLL::isEmpty() {
    return head == nullptr;
}

// add a node to the head of the list
void DLL::addToHead(int num) {
    DLLNode *ptr = new DLLNode(num);
    
    if(head==nullptr) {     // special case if the list is empty
        head = tail = ptr;  // ptr becomes both head and tail
    }
    else {
        ptr->next = head;   // point new node's next to old head
        head->prev = ptr;   // point old head's prev to ptr
        head = ptr;         // update head
    }
}

// add a node to the tail of the list
void DLL::addToTail(int num) {
    DLLNode *ptr = new DLLNode(num);

    if(tail==nullptr) {
        head = tail = ptr;      // ptr becomes both head and tail
    }
    else {
        ptr->prev = tail;       // point new node's prev to old tail
        tail->next = ptr;       // points old tail's next to ptr
        tail = ptr;             // update tail
    }
}

// delete head node and update head pointer to next node
void DLL::deleteFromHead() {
    if(head==tail) {
        delete head;        // delete head node, now the list is empty
        head = tail = nullptr; // null out head and tail
    }
    else {
        head = head->next;      // update head to nextt node
        delete head->prev;      // delete old head
        head->prev = nullptr;   // null out prev of new head
    }
}

// delete tail node and update tail pointer to previous node
void DLL::deleteFromTail() {
    if(head==tail) {
        delete tail;                // delete tail node, now the list is empty
        head = tail = nullptr;      // null out head and tail
    }
    else {
        tail = tail->prev;      // update tail to previous node
        delete tail->next;      // delete old tail
        tail->next = nullptr;   // null out next of new tail
    }
}

// delete the node with info's value as num
void DLL::deleteNode(int num) {
    if(head!=nullptr) {
        DLLNode *ptr = head;

        for( ; ptr!=nullptr; ptr=ptr->next) {
            if(ptr->info == num) {
            if(head==tail) {
                head = tail =nullptr;       // now the list becomes empty
            }
            else if(ptr==head) {
                head = head->next;
                head->prev = nullptr;   // head prev pointer is nulled out
            }
            else if(ptr==tail) {
                tail = tail->prev;
                tail->next = nullptr;   // tail next pointer is nulled out
            }
            else {
                ptr->prev->next = ptr->next;    
                ptr->next->prev = ptr->prev;
            }

            // std::cout << ptr->info << " deleted" << std::endl;

            delete ptr;     // delete the current node
            return;
            }
        }
    }
}

// delete all the nodes with info's value as num
void DLL::deleteNodes(int num) {
    if(head!=nullptr) {
        DLLNode *ptr, *temp;
        ptr = head;
        temp = nullptr;

        for( ; ptr!=nullptr; ) {
            if(ptr->info == num) {
            if(head==tail) {
                head = tail =nullptr;
            }
            else if(ptr==head) {
                head = head->next;
                head->prev = nullptr;
            }
            else if(ptr==tail) {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }

            // std::cout << ptr->info << " deleted" << std::endl;

            temp = ptr;
            ptr = ptr->next;
            delete temp;     // delete the current node
            }
            else 
                ptr=ptr->next;
        }
    }
}

// not tested
// returns true if num is in the list
bool DLL::isInList(int num) {
    if(head!=nullptr) {
        DLLNode *ptr = head;
        for( ; ptr!=nullptr; ptr = ptr->next) {
            if(ptr->info==num) return true;
        }
        return false;
    }
    else 
        return false;
}

#ifndef _INTSLL_H_
#define _INTSLL_H_

#include <vector>
#include <initializer_list>

// class for a single node of the list
template <typename type>
class SLLNode {
    public:
        type info;               // integer in current node
        SLLNode<type> *next;       // pointer to the next node
        SLLNode();       // default constructor SLLNode(0,0)
        SLLNode(type el=0, SLLNode* ptr={nullptr});  // constructor info = el, next = ptr
        ~SLLNode();     // Destructor
};

// class for the singly linked list
template <typename type>
class SLL {
private:
    void reverseSubList(SLLNode<type>* prev, SLLNode<type>* first);
public:
    SLLNode<type> *head,*tail;
    int sizeOfList;
// public:
    SLL();              // default no args constructor
    SLL(std::initializer_list<type> &lst);
    SLL(const SLL<type> &list);         // copy constructor
    ~SLL();             // destructor

    int size() const;       // returns the size of the list
    bool isEmpty() const;   // returns true if list is empty

    void addToHead(type data);      // add a node to head of the list
    void addToTail(type data);      // add a node to tail of list

    void insertAt(type data, int index);    // insert data at index
    void insertAfter(type data, int index); // insert data after node at index
    void insertAt(type data, SLLNode<type>* &ptr);       // insert data at node pointed to by ptr
    void insertAfter(type data, SLLNode<type>* &ptr);    // insert data after node pointed to by ptr
    void append(SLL<type> &list);   // attach list head to tail of the calling list

    type deleteFromHead();          // delete head and return its info
    type deleteFromTail();          // delete tail and return its info
    void deleteNodeAt(int index);   // delete node by index
    void deleteNode(type data);     // delete a node with info data
    void deleteNodes(type data);    // deletes all the nodes with info data

    void clear();                   // delete the contents of the list
    void print() const;             // prints the elements of list line by line
    bool isInList(type data) const; // returns true if data is in list
    void sort();                    // sort the list
    void merge(SLL<type> &list);    // merge two sorted list in one sorted listed
    void reverse();                 // reverse the list

    // overloaded operators
    SLL<type> &operator=(const SLL<type> &list);        // assignment operator
    type &operator[](int index);                        // subscript operator
    type operator[](int index) const;                   // subscript operator for const list
    bool operator==(const SLL<type> &list);             // equality operator
};

template <typename type>
SLL<type> &operator+(const SLL<type> &lhs, const SLL<type> &rhs);
template <typename type>
SLL<type> &operator+(const SLL<type> &lhs, type data);
template <typename type>
SLL<type> &operator+(type data, const SLL<type> &rhs);

#endif
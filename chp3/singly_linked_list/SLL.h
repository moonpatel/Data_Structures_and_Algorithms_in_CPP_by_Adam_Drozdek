#ifndef _INTSLL_H_
#define _INTSLL_H_

#include <vector>

// class for a single node of the list
template <typename type>
class SLLNode {
    public:
        type info;               // integer in current node
        SLLNode<type> *next;       // pointer to the next node
        SLLNode();       // default constructor SLLNode(0,0)
        SLLNode(type el=0, SLLNode* ptr={nullptr});  // constructor info = el, next = ptr
};

// class for the singly linked list
template <typename type>
class SLL {
public:
    SLLNode<type> *head,*tail;
    int sizeOfList;
// public:
    SLL();              // default no args constructor
    // SLL(std::vector<type> list);  // initialize SLL with array
    SLL(const SLL<type> &list);         // copy constructor
    ~SLL();             // destructor

    // overloaded operators
    SLL<type> &operator=(const SLL<type> &list);        // assignment operator
    SLLNode<type> operator[](int index);
    bool operator==(const SLL<type> &list);



    int size() const;   // returns the size of the list
    bool isEmpty() const;

    void addToHead(type data);      // add a node to head of the list
    void addToTail(type data);      // add a node to tail of list

    type deleteFromTail();          // delete tail and return its info
    type deleteFromHead();          // delete head and return its info
    void deleteNode(type data);     // delete a node with info data
    void deleteNodes(type data);    // deletes all the nodes with info data

    void clear();                   // delete the contents of the list
    void print() const;             // prints the elements of list line by line
    bool isInList(type data) const; // returns true if data is in list
    void sort();                    // sort the list
    void merge(SLL<type> &list);     // merge two sorted list in one sorted listed
};

template <typename type>
SLL<type> &operator+(const SLL<type> &lhs, const SLL<type> &rhs);
template <typename type>
SLL<type> &operator+(const SLL<type> &lhs, type data);
template <typename type>
SLL<type> &operator+(type data, const SLL<type> &rhs);

#endif
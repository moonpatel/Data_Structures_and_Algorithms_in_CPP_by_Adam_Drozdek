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
public:
    using size_type = unsigned long int;
    using iterator = SLLNode<type>*;

    SLL();                          // default no args constructor
    SLL(const SLL<type> &list);     // copy constructor
    SLL(SLL<type> &&list);          // move constructor
    ~SLL();             // destructor

    // iterator class for the list
    class iterator {
    public:
        iterator(ptr);
        iterator &operator++() {curr=curr->next; return *this;}
        type &operator*() {return curr->info;}

        bool operator==(const iterator &b) {return *this==b;}
        bool operator!=(const iterator &b) {return *this!=b;}
    private:
        SLLNode<type>* curr;    // current iterator
    };

    iterator begin();   // iterator to the head of list
    iterator end();     // iterator to the next to tail member of list

    type &front();      // return head
    type &back();       // return tail

    // insert value at node pointed by iter and return an iterator to the value
    iterator &insert(iterator iter, type value);
    iterator &erase(iterator iter);     // erase node pointed to by iterator and return an iterator to the next node

    const size_type size() const;       // returns the size of the list
    const bool isEmpty() const;   // returns true if list is empty

    void push_back(const type &data);      // add a node to tail of list
    void push_front(const type &data);      // add a node to head of the list
    void pop_back();          // delete tail and return its info
    void pop_front();          // delete head and return its info

    void insertAt(type data, size_type index);    // insert data at index
    void insertAfter(type data, size_type index); // insert data after node at index
    void insertAt(type data, SLLNode<type>* &ptr);       // insert data at node pointed to by ptr
    void insertAfter(type data, SLLNode<type>* &ptr);    // insert data after node pointed to by ptr
    void append(SLL<type> &list);   // attach list head to tail of the calling list

    void deleteNodeAt(size_type index);   // delete node by index
    void deleteNode(type data);     // delete a node with info data
    void deleteNodes(type data);    // deletes all the nodes with info data

    void clear();                   // delete the contents of the list
    const void print() const;             // prints the elements of list line by line
    bool isInList(type data) const; // returns true if data is in list
    void sort();                    // sort the list
    void merge(SLL<type> &list);    // merge two sorted list in one sorted listed
    void reverse();                 // reverse the list

    // overloaded operators
    SLL<type> &operator=(const SLL<type> &list);        // assignment operator
    type &operator[](size_type index);                        // subscript operator
    type operator[](size_type index) const;                   // subscript operator for const list
    bool operator==(const SLL<type> &list);             // equality operator

    friend SLL<type> &operator+(const SLL<type> &lhs, const SLL<type> &rhs);
    friend SLL<type> &operator+(const SLL<type> &lhs, type data);
    friend SLL<type> &operator+(type data, const SLL<type> &rhs);
private:
    void reverseSubList(SLLNode<type>* prev, SLLNode<type>* first);
    SLLNode<type> *head;
    SLLNode<type> *tail;
    size_type sizeOfList;
};

#endif
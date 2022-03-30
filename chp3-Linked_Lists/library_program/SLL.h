#ifndef _INTSLL_H_
#define _INTSLL_H_

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
    private:
        SLLNode<type> *head,*tail;
        int sizeOfList;
    public:
        SLL();        // default no args constructor
        ~SLL();       // destructor
        int size() const;     // returns the size of the list
        bool isEmpty() const;
        
        void addToHead(type data);    // add a node to head of the list
        void addToTail(type data);    // add a node to tail of list
        
        type deleteFromTail();    // delete tail and return its info
        type deleteFromHead();    // delete head and return its info
        void deleteNode(type data);    // delete a node with info data
        void deleteNodes(type data);      // deletes all the nodes with info data

        void clear();                   // delete the contents of the list
        void print() const;     // prints the elements of list line by line
        bool isInList(type data) const; // returns true if data is in list
        
};

#endif

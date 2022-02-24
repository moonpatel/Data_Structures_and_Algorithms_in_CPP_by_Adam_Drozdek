#ifndef _INTSLL_H_
#define _INTSLL_H_

// class for a single node of the list
class IntSLLNode {
    public:
        int info;               // integer in current node
        IntSLLNode *next;       // pointer to the next node
        IntSLLNode();       // default constructor IntSLLNode(0,0)
        IntSLLNode(int el=0, IntSLLNode* ptr={nullptr});  // constructor info = el, next = ptr
};

// class for the singly linked list
class IntSLL {
    private:
        IntSLLNode *head,*tail;
        int list_size;

    public:
        IntSLL();        // default no args constructor
        ~IntSLL();       // destructor
        int size();     // returns size of the list

        // checking functions
        bool isEmpty();
        bool isInList(int num) const; // returns true if num is in list
        
        // list modifiers
        void addToHead(int num);    // add a node to head of the list
        void addToTail(int num);    // add a node to tail of list
        int deleteFromHead();    // delete head and return its info
        int deleteFromTail();    // delete tail and return its info
        void deleteNode(int num);    // delete a node with info num
        void deleteNodes(int num);      // deletes all the nodes with info num

        // print funtion
        void print() const;     // prints the elements of list line by line
        
        // overloaded operators
        friend IntSLL &operator+(IntSLL &list, int num);       // add num to tail
        friend IntSLL &operator+(int num, IntSLL &list);       // add num to head
        int &operator[](int index);        // access list elements through their index
        
};

#endif

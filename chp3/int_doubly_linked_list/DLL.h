#ifndef _DLL_H_
#define _DLL_H_

class DLLNode {
    public:
        int info;
        DLLNode *next, *prev;
        DLLNode();
        DLLNode(int num);
};

class DLL {
    private:
        DLLNode *head, *tail;
    public:
        DLL();
        bool isEmpty();
        void addToHead(int num);    // add info to head
        void addToTail(int num);    // add info to tail
        void deleteFromHead();      // delete head node
        void deleteFromTail();      // delete tail node
        void deleteNode(int num);   // delete all occurences of num from list
        void deleteNodes(int num);  // delete num from the list
        bool isInList(int num);     // returns true if num is in the list
};

#endif
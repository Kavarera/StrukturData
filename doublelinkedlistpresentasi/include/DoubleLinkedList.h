#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "Node.h"

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    bool isEmpty();
    int getSize();
    void insertFront(int value);
    void insertBack(int value);
    void removeFront();
    void removeBack();
    void removeMiddle(int value);
    void displayNodes();
    void specialDisplayNodes(int value);
};

#endif
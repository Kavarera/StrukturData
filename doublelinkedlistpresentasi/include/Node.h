#ifndef NODE_H
#define NODE_H


class Node {
private:
    int data;
    Node* prev;
    Node* next;

public:
    Node(int value, Node* prev = nullptr, Node* next = nullptr);
    int getData();
    void setData(int value);
    Node* getPrev();
    void setPrev(Node* node);
    Node* getNext();
    void setNext(Node* node);
};

#endif
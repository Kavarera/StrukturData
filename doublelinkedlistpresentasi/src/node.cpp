#include "../include/Node.h"

#include <string>
#include <typeinfo>
#include <iostream>


Node::Node(int value, Node* prev, Node* next) {
    setData(value);
    this->next = prev;
    this->prev = next;
}
void Node::setData(int value) {
    this->data = value;
}
int Node::getData() {
    return data;
}

Node* Node::getNext() {
    return next;
}

Node* Node::getPrev() {
    return prev;
}

void Node::setNext(Node* next) {
    this->next = next;
}

void Node::setPrev(Node* prev) {
    this->prev = prev;
}
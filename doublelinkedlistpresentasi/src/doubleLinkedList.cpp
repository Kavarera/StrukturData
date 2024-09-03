#include "../include/DoubleLinkedList.h"

#include <string>
#include <iostream>

DoubleLinkedList::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

DoubleLinkedList::~DoubleLinkedList() {
    while (!isEmpty()) {
        removeFront();
    }
}

bool DoubleLinkedList::isEmpty() {
    return size == 0;
}

int DoubleLinkedList::getSize() {
    return size;
}

void DoubleLinkedList::insertFront(int value) {
    Node* newNode = new Node(value);

    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }

    size++;
}

void DoubleLinkedList::insertBack(int value) {
    Node* newNode = new Node(value);

    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->setPrev(tail);
        tail->setNext(newNode);
        tail = newNode;
    }

    size++;
}

void DoubleLinkedList::removeFront() {
    if (isEmpty()) {
        return;
    }

    Node* temp = head;

    if (size == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->getNext();
        head->setPrev(nullptr);
    }

    delete temp;
    size--;
}

void DoubleLinkedList::removeBack() {
    if (isEmpty()) {
        return;
    }

    Node* temp = tail;

    if (size == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->getPrev();
        tail->setNext(nullptr);
    }

    delete temp;
    size--;
}

void DoubleLinkedList::removeMiddle(int value) {
    if (isEmpty()) {
        return;
    }

    Node* current = head;

    while (current != nullptr) {
        if (current->getData() == value) { //periksa kondisi
            if (current == head) { //kalau depan
                removeFront();
            } else if (current == tail) { //kalau belakang
                removeBack();
            } else {
                current->getPrev()->setNext(current->getNext());
                current->getNext()->setPrev(current->getPrev());
                delete current;
                size--;
            }

            return;
        }

        current = current->getNext();
    }
}

void DoubleLinkedList::specialDisplayNodes(int value){
    if (isEmpty()) {
            return;
    }
    Node* current = head;


    while(current!=nullptr){ //progress 1 sebaris warna merah
        if(current->getData() == value){
            std::cout << "\033[41;30m" << current->getData() << "\033[0m\t";
            current = current->getNext();
        }
        else{
            std::cout << current->getData() << "\t";
            current = current->getNext();
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    current=head; //reseting current
    while (current != nullptr) {//progress 2 dibawa keatas.
        if(current->getData() != value){
            std::cout << " " << "\t";
            current = current->getNext();
        }
        else{
            std::cout << "\033[41;30m" << current->getData() << "\033[0m\t"<<std::endl;
            break;
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    current = head;
    while (current != nullptr) {//progress terakhir
        if(current->getData() != value){
            std::cout <<current->getData() << "\t";
        }
        if(current->getData() == value){
            std::cout << " " << "\t";
        }
        current = current->getNext();
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void DoubleLinkedList::displayNodes() {
    if (isEmpty()) {
        return;
    }

    Node* current = head;

    while (current != nullptr) {
        std::cout << current->getData() << "\t";
        current = current->getNext();
    }
    std::cout << std::endl;

    current = head;

    // Print the descriptions of the nodes
    while (current != nullptr) {
        if (current == head) {
            std::cout << "head\t";
        } else if (current == tail) {
            std::cout << "tail\t";
        } else {
            std::cout << "\t";
        }
        current = current->getNext();
    }
    std::cout << std::endl;
}
#pragma once

/*! \class Double Linked List
    \brief A double linked list data structure
*/

#include "doubleLinkedList.h"
using namespace std;
DoubleLinkedList::DoubleLinkedList() { size = 0; }

DoubleLinkedList::DoubleLinkedList(int iData) {
    //!< Creates a new node with the given date and sets a null pointer at the previous and next node
    shared_ptr<Node>firstNode(new Node(iData, nullptr, nullptr));
    //!< Sets the newly created node as current node
    Current = firstNode;
    //!< Updades the head and the tail with the newly created node, and increases the size of the list
    Head = Current;
    Tail = Current;
    size = 1;
}
DoubleLinkedList::~DoubleLinkedList() {
    cout << "Deleted";
}
void  DoubleLinkedList::push_front(int data) {
    //!< creates a new node which has the previous node a null pointer and the next node the head
    shared_ptr<Node>tmp(new Node(data, nullptr, Head));
    //!< for the current Head sets for the previous node the new node
    Head->setPrev(tmp);
    //!< Updates the head with the newly created node;
    Head = tmp;
    //!< increases the size of the list
    size = size + 1;
}
void DoubleLinkedList::push_back(int data) {
    //!< creates a new node which has as previous node the tail and the next node a null pointer
    shared_ptr<Node>tmp(new Node(data, Tail , nullptr));
    //!< sets the new node as previous node of the tail 
    Tail->setNext(tmp);
    //!< sets the new created node as tail
    Tail = tmp;
    //!< increases the size of the list
    size = size + 1;
}
void DoubleLinkedList::push_after(int data) {
    //!< creates a new node which has as prev node the current node and the next node of the current node as next node
    shared_ptr<Node>tmp(new Node(data, Current, Current->getNext()));
    //!< sets the new node as the previous node for the next node of the current node
    Current->getNext()->setPrev(tmp);
    //!< sets the new node as next node for the current node
    Current->setNext(tmp);
    size = size + 1;
}
void DoubleLinkedList::push_before(int data) {
    //!< creates a new node which has as previous node the previous node of the current node and the next node the current node
    shared_ptr<Node>tmp(new Node(data, Current->getPrev(), Current));
    //!< sets for the previous node of the current node as next node the new node
    Current->getPrev()->setNext(tmp);
    //!< sets for the current node as the previous node the new node
    Current->setPrev(tmp);
    //!< increses the size
    size = size + 1;
}
void DoubleLinkedList::pop_head() {
}
void DoubleLinkedList::pop_tail() {
}
void DoubleLinkedList::sort(bool ascending) {
}
bool DoubleLinkedList::empty() {
    return size == 0;
};
int DoubleLinkedList::sizeOf() {
    return size;
}
int DoubleLinkedList::look_head() {
    return 1;
}
int DoubleLinkedList::look_tail() {
    return 1;
}
int DoubleLinkedList::look_current() {
    return Current->getData();
}
void DoubleLinkedList::move_up() {
    Current = Current->getPrev();
}
void DoubleLinkedList::move_down() {
    Current = Current->getNext();
}


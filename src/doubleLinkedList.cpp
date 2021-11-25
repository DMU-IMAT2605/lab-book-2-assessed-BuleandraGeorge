#pragma once

/*! \class Double Linked List
    \brief A double linked list data structure
*/

#include "doubleLinkedList.h"
using namespace std;
DoubleLinkedList::DoubleLinkedList() { size = 0; }

DoubleLinkedList::DoubleLinkedList(int iData) {
    shared_ptr<Node>firstNode(new Node(iData, nullptr, nullptr));
    Current = firstNode;
    Head = Current;
    Tail = Current;
    size = 1;
}
DoubleLinkedList::~DoubleLinkedList() {
    cout << "Deleted";
}
void  DoubleLinkedList::push_front(int data) {
    shared_ptr<Node>tmp(new Node(data, nullptr, Head));
    Head->setPrev(tmp);
    Head = tmp;
    size = size + 1;
}
void DoubleLinkedList::push_back(int data) {
}
void DoubleLinkedList::push_after(int data) {
}
void DoubleLinkedList::push_before(int data) {
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


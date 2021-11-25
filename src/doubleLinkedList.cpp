#pragma once

/*! \class Double Linked List
    \brief A double linked list data structure
*/

#include "doubleLinkedList.h"
using namespace std;
DoubleLinkedList::DoubleLinkedList() {
    Head = nullptr;
    Tail = nullptr;
    Current = nullptr;
    size = 0; 
}

DoubleLinkedList::~DoubleLinkedList() {
    cout << "Deleted";
}
void  DoubleLinkedList::push_front(int data) {
    //!< creates a new node which has the previous node a null pointer and the next node the head
    shared_ptr<Node>tmp(new Node(data, nullptr, Head));
    if (!empty())
    {
        
        //!< if the list is not empty sets as previous node of the head the new node
        Head->setPrev(tmp);
        //!< and the new node is the set as head
        Head = tmp;
        
    }
    //!< else initialize the tail,head and the current with the new node;
    else Tail=Head=Current = tmp;
    size++;
}
void DoubleLinkedList::push_back(int data) {
    //!< creates a new node which has as previous node the tail and the next node a null pointer
    shared_ptr<Node>tmp(new Node(data, Tail , nullptr));
    //!< sets the new node as previous node of the tail 
    if (Tail!=nullptr) Tail->setNext(tmp);
    //!< sets the new created node as tail
    Tail = tmp;
    //!< increases the size of the list
    size = size + 1;
}
void DoubleLinkedList::push_after(int data) {
    if (Current != nullptr)
    {
        if (Current->getNext() != nullptr)
        {
            shared_ptr<Node>tmp(new Node(data, Current, Current->getNext()));
            Current->getNext()->setPrev(tmp);
            Current->setNext(tmp);
            size++;
        }
    }
    else push_back(data);
}
void DoubleLinkedList::push_before(int data) {
    //!< creates a new node which has as previous node the previous node of the current node and the next node the current node
    shared_ptr<Node>tmp(new Node(data, Current->getPrev(), Current));
    //!< sets for the previous node of the current node as next node the new node if the current node is not the head else sets the new node as head
    if (Current->getPrev() != nullptr) Current->getPrev()->setNext(tmp);
    else Head = tmp;
  
    //!< sets for the current node as the previous node the new node
    Current->setPrev(tmp);
    //!< increses the size
    size = size + 1;
}
void DoubleLinkedList::pop_head() {
    Head = Head->getNext();
    Head->setPrev(nullptr);
    size = size - 1;
}
void DoubleLinkedList::pop_tail() {
    Tail = Tail->getPrev();
    Tail->setNext(nullptr);
    size = size - 1;
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
    return Head->getData();
}
int DoubleLinkedList::look_tail() {
    return Tail->getData();
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


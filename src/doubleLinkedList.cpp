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
    //!< creates a new node which has as previous node the tail and the next node a null pointer, in other words a new tail which has as prev node the current tail
    shared_ptr<Node>tmp(new Node(data, Tail, nullptr));
    if (!empty())
    {

        //!< if the list is not empty sets as next node of the tail the new node, the current tail has as next node the new node and becomes a common node
        Tail->setNext(tmp);
        //!< and the new node is the set as Tail, updates the value of the tail with the new node.
        Tail = tmp;

    }
    //!< else initialize the tail, head and the current with the new node;
    else Tail = Head = Current = tmp;
    size++;
}
void DoubleLinkedList::push_after(int data) {
    if (!empty())
    {
        shared_ptr<Node>tmp(new Node(data, Current, Current->getNext()));
        if (Current->getNext() != nullptr)
        {
            Current->getNext()->setPrev(tmp);
            Current->setNext(tmp);
            size++;
        }
        else Tail = tmp;

    }
    else
    {
        shared_ptr<Node>tmp(new Node(data, nullptr, nullptr));
        Tail = Head = Current = tmp;
    }
        
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


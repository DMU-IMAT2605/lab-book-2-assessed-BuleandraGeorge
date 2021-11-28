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
    size=size+1;
    

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
    { //!< if the list is not empty creates a new node which has as previous node the current node and the next node the next node of the current node
        shared_ptr<Node>tmp(new Node(data, Current, Current->getNext()));
        if (Current->getNext() != nullptr)
        {   //!< if the current node is not the tail, sets for the previous node of the next node of the current node the new node
            Current->getNext()->setPrev(tmp);
            //!< for the current node sets as next node the new node
            Current->setNext(tmp);
            //!< increases the size
            size++;
        }
        //!< if the current node is the tail then updates the Tail with the new node
        else {
            //!< for the current node sets as next node the new node
            Current->setNext(tmp);
            Tail = tmp;
            size = size + 1;
        }

    }
    else
        //!< if the list is empty creates a new node and it sets as tail head and current
    {
        shared_ptr<Node>tmp(new Node(data, nullptr, nullptr));
        Tail = Head = Current = tmp;
        size = size + 1;
    }
        
}
void DoubleLinkedList::push_before(int data) {
    if (!empty())
    { //!< if the list is not empty creates a new node which has as previous node the previous node of the current node and the next node the current node
        shared_ptr<Node>tmp(new Node(data, Current->getPrev(), Current));
        if (Current->getPrev() != nullptr)
        {   //!< if the current node is not the head, sets for the previous node of the next node of the current node the new node
            Current->getPrev()->setNext(tmp);
            //!< for the current node sets as previous node the new node
            Current->setPrev(tmp);
            //!< increases the size
            size=size+1;
        }
        //!< if the current node is the Head then updates the Tail with the new node
        else {
            Current->setPrev(tmp);
            Head = tmp;
            size = size + 1;
        }

    }
    else
        //!< if the list is empty creates a new node and it sets as tail head and current
    {
        shared_ptr<Node>tmp(new Node(data, nullptr, nullptr));
        Tail = Head = Current = tmp;
        size = size + 1;
    }
}
void DoubleLinkedList::pop_head() {
    if(!empty())
    {
        shared_ptr<Node>tmp = Head->getNext();
        Head->setNext(nullptr);
        if (tmp != nullptr) tmp->setPrev(nullptr);
        else Tail = Current = Head = nullptr;
        size = size - 1;
        
        if (Head == Current)
        {
            Head = Current = tmp;
        }
        else
        {
            Head = tmp;
        }

    }

}
void DoubleLinkedList::pop_tail() {
    if (!empty())
    {
   
        shared_ptr<Node>tmp = Tail->getPrev();
        Tail->setPrev(nullptr);
        if (tmp != nullptr)tmp->setNext(nullptr);
        else Tail = Head = Current = nullptr;
        size = size - 1;
        if (Tail == Current)
        {
            Tail = Current = tmp;
            
        }
        else
        {
            Tail = tmp;
        }
        
    }
}
void DoubleLinkedList::sort(bool ascending) {
    bool change = true;
    while (change)
    {
        change = false;
        Current = Head;
        while(Current!=Tail)
        {
            bool greater;
            greater = ((Current->getData()) > (Current->getNext()->getData())) ? true : false;
            if (greater==ascending)
            {
                swapWithNext();
                change = true;
            }
            else move_down();
        }
    }
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
void DoubleLinkedList::swapWithNext()
{
    if (Current != Tail)
    {
        shared_ptr<Node>NEXT = Current->getNext();
        if (Current == Head) Head = NEXT;
        shared_ptr<Node>PREVIOUS = Current->getPrev();
        Current->setPrev(NEXT);
        Current->setNext(NEXT->getNext());
        if (NEXT->getNext() != nullptr) NEXT->getNext()->setPrev(Current); else Tail = Current;
        NEXT->setPrev(PREVIOUS);
        NEXT->setNext(Current);
        if(PREVIOUS!=nullptr)PREVIOUS->setNext(NEXT);
    }
    

}


#pragma once

/*! \class Double Linked List
    \brief A double linked list data structure
*/

#include "Node.h"
using namespace std;

class DoubleLinkedList
{
private :
    shared_ptr<Node> Head;
    shared_ptr<Node> Tail;
    int size;
    shared_ptr<Node> Current;

public :
    DoubleLinkedList(); //!< default constructor
    ~DoubleLinkedList(); //!< default deconstructor
    void push_front(int data); //!< inserts a node at front
    void push_back(int data);//!< inserts a node at back
    void push_after(int data);//!< inserts a node after the current node
    void push_before(int data);//!< inserts a node before the current node
    void pop_head(); //!< removes the head of the list
    void pop_tail(); //!< removes the tail of the list
    void sort(bool ascending); //!< sorts the list ascending or descending \param ascending reprezents the way of the sort
    bool empty();//!< returns if the list is empty or not;
    int size();//!< returns the size of the list
    int look_head();//!< returns the data in the head
    int look_tail();//!< returns the data in the tail
    int look_current();//!< returns the data in the current 
    void move_up();//!< moves the pointer to the next upper node of the current node
    void move_down();//!< moves the pointer to the next lower node of the current node
};


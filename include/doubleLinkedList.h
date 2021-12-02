#pragma once

/*! \class DoubleLinkedList
    \brief A double linked list data structure
    \detailed Provides functionalities as adding and removing the nodes as much as sorting or just retreiving the data from the nodes and traversing the list.
*/

#include "Node.h"
#include <set>
using namespace std;
template <class G>
class DoubleLinkedList
{
private :
    shared_ptr<Node<G>> Head;
    shared_ptr<Node<G>> Tail;
    int size;
    shared_ptr<Node<G>> Current;
    void swapWithNext();//! swaps the position of the current node with the next node
    void findLeaf(shared_ptr<Node<G>> node, G value); 
    void getTreeLeafs(shared_ptr<Node<G>> node);
public :
    DoubleLinkedList(); //!<default constructor
    ~DoubleLinkedList(); //!< default deconstructor
    void push_front(G data); //!< inserts a node at front
    void push_back(G data);//!< inserts a node at back
    void push_after(G data);//!< inserts a node after the current node
    void push_before(G data);//!< inserts a node before the current node
    void pop_head(); //!< removes the head of the list
    void pop_tail(); //!< removes the tail of the list
    void sort(bool ascending); //!< sorts the list ascending or descending \param ascending reprezents the way of the sort
    bool empty();//!< returns if the list is empty or not;
    int sizeOf();//!< returns the size of the list
    G look_head();//!< returns the data in the head
    G look_tail();//!< returns the data in the tail
    G look_current();//!< returns the data in the current 
    void move_up();//!< moves the pointer to the next upper node of the current node
    void move_down();//!< moves the pointer to the next lower node of the current node
 
};



#include "doubleLinkedList.h"
using namespace std;
template <class G>
DoubleLinkedList<G>::DoubleLinkedList() {
    Head = nullptr;
    Tail = nullptr;
    Current = nullptr;
    size = 0;
}
template <class G>
DoubleLinkedList<G>::~DoubleLinkedList() {
    cout << "Deleted";
}
template <class G>
void  DoubleLinkedList<G>::push_front(G data) {
    //!< creates a new node which has the previous node a null pointer and the next node the head
    shared_ptr<Node<G>>tmp(new Node<G>(data, nullptr, Head));
    if (!empty())
    {

        //!< if the list is not empty sets as previous node of the head the new node
        Head->setPrev(tmp);
        //!< and the new node is the set as head
        Head = tmp;
    }
    //!< else initialize the tail,head and the current with the new node;
    else Tail = Head = Current = tmp;
    size = size + 1;


}
template <class G>
void DoubleLinkedList<G>::push_back(G data) {
    //!< creates a new node which has as previous node the tail and the next node a null pointer, in other words a new tail which has as prev node the current tail
    shared_ptr<Node<G>>tmp(new Node<G>(data, Tail, nullptr));
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
template <class G>
void DoubleLinkedList<G>::push_after(G data) {
    if (!empty())
    { //!< if the list is not empty creates a new node which has as previous node the current node and the next node the next node of the current node
        shared_ptr<Node<G>>tmp(new Node<G>(data, Current, Current->getNext()));
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
        shared_ptr<Node<G>>tmp(new Node<G>(data, nullptr, nullptr));
        Tail = Head = Current = tmp;
        size = size + 1;
    }

}
template <class G>
void DoubleLinkedList<G>::push_before(G data) {
    if (!empty())
    { //!< if the list is not empty creates a new node which has as previous node the previous node of the current node and the next node the current node
        shared_ptr<Node<G>>tmp(new Node<G>(data, Current->getPrev(), Current));
        if (Current->getPrev() != nullptr)
        {   //!< if the current node is not the head, sets for the previous node of the next node of the current node the new node
            Current->getPrev()->setNext(tmp);
            //!< for the current node sets as previous node the new node
            Current->setPrev(tmp);
            //!< increases the size
            size = size + 1;
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
        shared_ptr<Node<G>>tmp(new Node<G>(data, nullptr, nullptr));
        Tail = Head = Current = tmp;
        size = size + 1;
    }
}
template <class G>
void DoubleLinkedList<G>::pop_head() {
    if (!empty())
    {
        //!< creates a copy of the next node of the head
        shared_ptr<Node<G>>tmp = Head->getNext();
        //!< sets the next node of the head as null
        Head->setNext(nullptr);
        //!< if next node of the head is not null then set the previous node of the next node of the head as null 
        if (tmp != nullptr) tmp->setPrev(nullptr);
        //!< else that means that it's only one node in the list and then sets Tail Current and Head to nullptr
        else Tail = Current = Head = nullptr;
        size = size - 1;
        //!< updates the head and the current node if necessary
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
template <class G>
void DoubleLinkedList<G>::pop_tail() {
    if (!empty())
    {
        //!< creates a copy of the previous node of the tail
        shared_ptr<Node<G>>tmp = Tail->getPrev();
        //!<sets the previous node of the tails as null
        Tail->setPrev(nullptr);
        //!< if the previous node of the current tail is not null then set the next node of it to null
        if (tmp != nullptr)tmp->setNext(nullptr);
        //!< else the list becomes empty
        else Tail = Head = Current = nullptr;
        size = size - 1;
        //<! updates the tail and the current node accordingly
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
template <class G>
void DoubleLinkedList<G>::sort(bool ascending) {
 /*cout << "intrat in functie" << endl;
    shared_ptr<Node<G>>cpHead = Head;
    cout << "a mers copie la head" << endl;
    multiset<G>mySet;
    cout << "a mers creare de set" << endl;
    while (cpHead!=nullptr) {
        mySet.insert(cpHead->getData());
        cpHead = cpHead->getNext();
        cout << "a mers get next"<<endl;
    }
    multiset<int>::iterator it;
    cpHead = Head;
    for (it = mySet.begin();it != mySet.end();++it)
    {
        cout << *it << endl;
        cpHead->setData(*it);
        cpHead = cpHead->getNext();
    }
    */
    shared_ptr<Node<G>>Root(new Node<G>(Head->getData(), nullptr, nullptr));
 
    shared_ptr<Node<G>>Curr = Head->getNext();
    while (Curr != nullptr)
    {
        findLeaf(Root, Curr->getData());
        Curr = Curr->getNext();
    }
    getTreeLeafs(Root);
}
template <class G>
bool DoubleLinkedList<G>::empty() {
    return size == 0;
};
template <class G>
int DoubleLinkedList<G>::sizeOf() {
    return size;
}
template <class G>
G DoubleLinkedList<G>::look_head() {
    return Head->getData();
}
template <class G>
G DoubleLinkedList<G>::look_tail() {
    return Tail->getData();
}
template <class G>
G DoubleLinkedList<G>::look_current() {
    return Current->getData();
}
template <class G>
void DoubleLinkedList<G>::move_up() {
    Current = Current->getPrev();
}
template <class G>
void DoubleLinkedList<G>::move_down() {
    Current = Current->getNext();
}
template <class G>
void DoubleLinkedList<G>::swapWithNext()
{   //!< tests if the current node is different by the Tail
    if (Current != Tail)
    {
        //!< Creates a copy of the next node of the current node
        shared_ptr<Node<G>>NEXT = Current->getNext();
        //!< if the current happens to be the head, updates the head with the next node
        if (Current == Head) Head = NEXT;
        //!< It does a copy of the previous node of the current node
        shared_ptr<Node<G>>PREVIOUS = Current->getPrev();
        //!< Sets the previous and the next node of the current node with previous and next node of the next node
        Current->setPrev(NEXT);
        Current->setNext(NEXT->getNext());
        //!< if Next node is not the last node in the list sets as previous node the current node else updates the tail with the current node
        if (NEXT->getNext() != nullptr) NEXT->getNext()->setPrev(Current); else Tail = Current;
        //!< for the next node of the current node sets the previous with the value of the previous node  of the current node
        NEXT->setPrev(PREVIOUS);
        //!<for the next node of the next node of the current node sets the value of the next node to the current node
        NEXT->setNext(Current);
        //!< if the current node is not the head sets the 
        if (PREVIOUS != nullptr)PREVIOUS->setNext(NEXT);
    }
}
    template <class G>
    void DoubleLinkedList<G>::findLeaf(shared_ptr<Node<G>> root, G value)
    {
        cout << "founded leaf";
        if (root == nullptr) {
            shared_ptr<Node<G>>root(new Node<G>(value, nullptr, nullptr)); cout << "Created leaf";
        }
        else if (root->getData() <= value) findLeaf(root->getPrev(), value);
             else findLeaf(root->getNext(), value);
      
    }
    template <class G>
    void DoubleLinkedList<G>::getTreeLeafs(shared_ptr<Node<G>> root) {
        if (root != nullptr)
        {
            getTreeLeafs(root->getPrev());
            cout << root->getData();
            getTreeLeafs(root->getNext());
        }
        
    }


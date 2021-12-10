#pragma once
/*! \class Node
	\brief A double linked list node. Stores the data, the previous and the next node, and provides basic functionabilities as setting and receiving the surrounding nodes or receiving the stored data
*/
#include <memory>
#include <iostream>
using namespace std;
template <class G>
class Node
{
private:
	shared_ptr<Node<G>> next;
	shared_ptr<Node<G>> prev;
	
public:
	G data;
	Node(G data, shared_ptr<Node> prev, shared_ptr<Node> next); //!< Default constructor for a node
	//!< \param data reprezents the data stored in the node \param prev reprezents a pointer to the previos node \param next reprezents a pointer to the next node
	~Node(); //!< Default deconstructor for node
	G getData(); //!< returns the data stored in the node 
	shared_ptr<Node<G>> getPrev();//!< returns the previous node;
	shared_ptr<Node<G>> getNext();//!< returns the next node;
	void setPrev(shared_ptr<Node<G>> node);//!< sets the prev node
	void setNext(shared_ptr<Node<G>> node);//!< sets the next node
	void setData(G gdata);
};

template <class G>
Node<G>::Node(G iData, shared_ptr<Node<G>> pprev, shared_ptr<Node<G>> pnext)
{
	data = iData;
	prev = pprev;
	next = pnext;
}
template <class G>
Node<G>::~Node()
{
}
template <class G>
G Node<G>::getData()
{
	return data;
}
template <class G>
void Node<G>::setData(G gData)
{
	data=gData;
}
template <class G>
shared_ptr<Node<G>> Node<G>::getNext()
{
	return next;
}
template <class G>
shared_ptr<Node<G>> Node<G>::getPrev()
{
	return prev;
}
template <class G>
void Node<G>::setPrev(shared_ptr<Node<G>> node)
{
	prev = node;
}
template <class G>
void Node<G>::setNext(shared_ptr<Node<G>> node) {
	next = node;
}
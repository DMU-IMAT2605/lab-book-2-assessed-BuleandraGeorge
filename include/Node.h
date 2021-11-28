#pragma once
#include <iostream>
#include <memory>
using namespace std;
template <class G>
class Node
{
private:
	shared_ptr<Node<G>> next;
	shared_ptr<Node<G>> prev;
	G data;
	
public:
	Node(G data, shared_ptr<Node> prev, shared_ptr<Node> next); //!< Default constructor for a node
	//!< \param data reprezents the data stored in the node \param prev reprezents a pointer to the previos node \param next reprezents a pointer to the next node
	~Node(); //!< Default deconstructor for node
	G getData(); //!< returns the data stored in the node 
	shared_ptr<Node<G>> getPrev();//!< returns the previous node;
	shared_ptr<Node<G>> getNext();//!< returns the next node;
	void setPrev(shared_ptr<Node<G>> node);//!< sets the prev node;
	void setNext(shared_ptr<Node<G>> node);//!< sets the next node;
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
	cout << "node deleted with data: " << data << endl;
}
template <class G>
G Node<G>::getData()
{
	return data;
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
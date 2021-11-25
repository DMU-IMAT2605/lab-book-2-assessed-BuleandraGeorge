#pragma once
#include <iostream>
#include <memory>
using namespace std;

class Node
{
private:
	shared_ptr<Node> next;
	shared_ptr<Node> prev;
	int data;
	
public:
	Node(int data, shared_ptr<Node> prev, shared_ptr<Node> next); //!< Default constructor for a node
	//!< \param data reprezents the data stored in the node \param prev reprezents a pointer to the previos node \param next reprezents a pointer to the next node
	~Node(); //!< Default deconstructor for node
	int getData(); //!< returns the data stored in the node 
	shared_ptr<Node> getPrev();//!< returns the previous node;
	shared_ptr<Node> getNext();//!< returns the next node;
	void setPrev(shared_ptr<Node> node);//!< sets the prev node;
	void setNext(shared_ptr<Node> node);//!< sets the next node;
};


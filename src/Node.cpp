#include "Node.h"
#include <memory>
Node::Node(int iData, shared_ptr<Node> prev, shared_ptr<Node> next)
{
	data = iData;
	prev = prev;
	next = next;
}
Node::~Node()
{
	cout << "node deleted";
}
int Node::getData()
{
	return data;
}
shared_ptr<Node> Node::getNext()
{
	return next;
}
shared_ptr<Node> Node::getPrev()
{
	return prev;
}
void Node::setPrev(shared_ptr<Node> node)
{
	prev = node;
}
void Node::setNext(shared_ptr<Node> node) {
	next = node;
}
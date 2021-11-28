#include "Node.h"
#include <memory>
Node::Node(int iData, shared_ptr<Node> pprev, shared_ptr<Node> pnext)
{
	data = iData;
	prev = pprev;
	next = pnext;
}
Node::~Node()
{
	cout << "node deleted with data: "<<data<<endl;
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
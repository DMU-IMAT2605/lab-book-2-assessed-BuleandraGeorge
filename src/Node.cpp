#include "Node.h"
#include <memory>
Node::Node(int data, shared_ptr<Node> prev, shared_ptr<Node> next)
{
	data = data;
	prev = prev;
	next = next;
}
Node::~Node()
{
	cout << "node deleted";
}
int Node::getData()
{
	cout << data;
}
shared_ptr<Node> Node::getNext()
{
	return next;
}
shared_ptr<Node> Node::getPrev()
{
	return prev;
}
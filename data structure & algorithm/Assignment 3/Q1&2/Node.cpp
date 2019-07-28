#include "Node.h"



Node::Node(int x)
{
	left = 0;
	middle = 0;
	right = 0;
	type = 0;
	key2 = 0;
	key1 = x;
}


Node::~Node()
{
}

int Node::getType()
{
	return type;
}

int Node::getKey1()
{
	return key1;
}

int Node::getKey2()
{
	return key2;
}

void Node::setType(int x)
{
	type = x;
}

void Node::setKey1(int x)
{
	key1 = x;
}

void Node::setKey2(int x)
{
	key2 = x;
}
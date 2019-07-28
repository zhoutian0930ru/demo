#include "Node.h"


Node::Node(int x)
{
	left = 0;
	right = 0;
	key = x;
}

Node::~Node() {

}


int Node::getKey()
{
	return key;
}



void Node::setKey(int x)
{
	key = x;
}

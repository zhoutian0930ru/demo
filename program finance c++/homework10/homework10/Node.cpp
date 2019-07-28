//Node.cpp
//Name:Zhou Tian

#include "Node.h"

//constructor
Node::Node()
{
	this->next = NULL;
}//end constructor

//function setNode
void Node::setNode(string name, int no)
{
	itemName = name;
	itemNo = no;
}//end function setNode

//function getName
string Node::getName()
{
	return itemName;
}//end function getName

//function getNo
int Node::getNo()
{
	return itemNo;
}//end function getNo

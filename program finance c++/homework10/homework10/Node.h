//Node.h
//Name:Zhou Tian

#ifndef NODE_H
#define NODE_H
#include<string>
using namespace std;

#include"LinkedList.h"

class Node
{
	friend class LinkedList;
public:
	Node();
	void setNode(string, int);
	string getName();
	int getNo();
private:
	string itemName;
	int itemNo;
	Node *next;
};

#endif // !NODE_H


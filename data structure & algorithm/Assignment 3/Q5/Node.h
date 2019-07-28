#ifndef NODE_H
#define NODE_H


#include "BST.h"
class Node
{
	friend class BST;
public:
	Node(int);
	~Node();
	int getKey();
	void setKey(int);
private:
	Node * left;
	Node *right;
	int key;
};

#endif // !NODE_H

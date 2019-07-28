#ifndef TREE_H
#define TREE_H


#include "tree.h"
class Node
{
	friend class tree;
public:
	Node(int);
	~Node();
	int getType();
	int getKey1();
	int getKey2();
	void setType(int);
	void setKey1(int);
	void setKey2(int);
private:
	Node * left;
	Node *middle;
	Node *right;
	int key1,key2;
	int type; //0 is 2-node; 1 is 3-node
};

#endif // !TREE_H

#ifndef NODE_H
#define NODE_H

#include "Node.h"
class tree
{
	friend class Node;
public:
	tree();
	~tree();
	void insert(Node*);
	void print();
	void printByNode(Node*);
	void deleteByNode(Node*);
	int getNumb();
	int getCount();
	void rotateLeft(Node*);
	void rotateRight(Node*);
	void leanLeft();
	void leanRight();
private:
	int count;
	int numb;//number of node
	Node* root;

};

#endif // !1
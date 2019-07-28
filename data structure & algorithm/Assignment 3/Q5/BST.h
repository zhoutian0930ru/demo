#ifndef BST_H
#define BST_H

#include "Node.h"
class BST
{
	friend class Node;
public:
	BST();
	~BST();
	void insert(Node*);
	void print();
	void printByNode(Node*);
	void deleteByNode(Node*);
	int searchBynode(Node*,int,int);
	int searchRank(Node*, int,int);
	int getNumb();
	int getCount();
	int select(int);
	int rank(int);
private:
	int count;
	int resultKey;
	int numb;//number of node
	Node* root;

};

#endif // !1
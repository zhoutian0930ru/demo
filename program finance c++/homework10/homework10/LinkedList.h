//LinkedList.h
//Name:Zhou Tian

#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>using std::cout;

#include <new>
#include"Node.h"

class LinkedList
{
friend class Node;
public:
	LinkedList();
	~LinkedList();
	int size();
	void addToStart(Node *);
	void addToEnd(Node *);
	void printList();
	bool removeFromStart();
	bool removeFromEnd();
	void removeNodeFromList(int);
	void removeNodeFromList(string);
private:
	Node *myHead;
	Node *myTail;
	int mySize;
};

#endif // !LINKLIST_H


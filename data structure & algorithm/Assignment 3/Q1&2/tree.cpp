#include "tree.h"
#include <iostream>
using namespace std;


tree::tree()
{
	root = 0;
	count = 0;
	numb = 0;
}

tree::~tree()
{
	deleteByNode(root);
}

void tree::insert(Node* h)
{
	int sign = 0;
	numb++;
	if (root == 0)
		root = h;
	else {
		Node* temp;
		Node* mark;
		temp = root;
		mark = root;
		while (sign == 0) {
			if (temp->getType() == 0) {
				if (h->getKey1() < temp->getKey1()) {
					if (temp->left == 0) {
						mark = temp;
						sign = 1;
					}
					else
						count++;
					temp = temp->left;
				}
				else {
					if (temp->right == 0) {
						mark = temp;
						sign = 1;
					}			
					else
						count++;
					temp = temp->right;
				}
			}
			else {
				count++;
				mark = temp;
				if (h->getKey1() < temp->getKey1()) {
					if (temp->left == 0) {
						temp->left = h;
						sign = 1;
					}		
					temp = temp->left;
				}
				else {
					if (h->getKey1()>temp->getKey2()){
						if (temp->right == 0) {
							temp->right = h;
							sign = 1;
						}	
						temp = temp->right;
				    }
					else {
						if (temp->middle == 0) {
							temp->middle = h;
							sign = 1;
						}							
						temp = temp->middle;
					}
				}
			}
		}//end while
		if (mark->getType() == 0) {
			mark->setType(1);
			if (h->getKey1() > mark->getKey1()) {
				mark->setKey2(h->getKey1());
				
			}
			else {
				mark->setKey2(mark->getKey1());
				mark->setKey1(h->getKey1());
			}
			delete h;
		}
	}//end else
}

//ascending
void tree::print()
{
	if (numb != 0) {
		printByNode(root);
	}	
}

void tree::printByNode(Node* h)
{
	if (h == 0)
		return;
	else {
		if (h->getType() == 0) {
			printByNode(h->left);
			cout << h->getKey1() << endl;
			printByNode(h->right);
		}
		else {
			printByNode(h->left);
			cout << h->getKey1() << endl;
			printByNode(h->middle);
			cout << h->getKey2() << endl;
			printByNode(h->right);
		}		
	}
}

void tree::deleteByNode(Node* h)
{
	if (h == 0)
		return;
	else {
		if (h->getType() == 0) {
			deleteByNode(h->left);
			deleteByNode(h->right);
			delete h;
		}
		else {
			deleteByNode(h->left);
			deleteByNode(h->right);
			deleteByNode(h->middle);
			delete h;
		}
	}	
}

int tree::getNumb()
{
	return numb;
}

int tree::getCount()
{
	return count;
}

void tree::rotateLeft(Node* h)
{
	if (h == 0)
		return;
	else {
		if (h->getType() == 0) {
			rotateLeft(h->left);
			rotateLeft(h->right);
		}
		else {
			Node* x = new Node(h->getKey1());
			x->left = h->left;
			x->right = h->middle;
			h->left = x;
			h->middle = 0;
			h->setKey1(h->getKey2());
			h->setKey2(0);
			h->setType(0);
			rotateLeft(x->left);
			rotateLeft(x->right);
			rotateLeft(h->right);
		}
	}
}

void tree::rotateRight(Node* h)
{
	if (h == 0)
		return;
	else {
		if (h->getType() == 0) {
			rotateRight(h->left);
			rotateRight(h->right);
		}
		else {
			Node* x = new Node(h->getKey2());
			x->left = h->middle;
			x->right = h->right;
			h->right = x;
			h->middle = 0;
			h->setKey2(0);
			h->setType(0);
			rotateRight(x->left);
			rotateRight(x->right);
			rotateRight(h->left);
		}
	}
}
void tree::leanLeft() {
	if (root != 0) {
		rotateLeft(root);
	}
}
void tree::leanRight() {
	if (root != 0) {
		rotateRight(root);
	}
}
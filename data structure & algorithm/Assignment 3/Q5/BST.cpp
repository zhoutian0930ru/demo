#include "BST.h"
#include <iostream>
using namespace std;


BST::BST()
{
	root = 0;
	count = 0;
	numb = 0;
}

BST::~BST()
{
	deleteByNode(root);
}

void BST::insert(Node* h)
{
	int sign = 0;
	numb++;
	if (root == 0)
		root = h;
	else {
		Node* temp;
		temp = root;
		while (sign == 0) {
			count++;
			if (h->getKey() < temp->getKey()) {
				if (temp->left == 0) {
					temp->left = h;
					sign = 1;
				}
				temp = temp->left;
			}
			else {
				if (temp->right == 0) {
					temp->right = h;
					sign = 1;
				}
				temp = temp->right;
			}
		}//end while
	}
}

//ascending
void BST::print()
{
	if (numb != 0) {
		printByNode(root);
	}
	else {
		cout << "It is empty." << endl;
	}
}

void BST::printByNode(Node* h)
{
	if (h == 0)
		return;
	else {
		printByNode(h->left);
		cout << h->getKey() << endl;
		printByNode(h->right);
	}
}

void BST::deleteByNode(Node* h)
{
	if (h == 0)
		return;
	else {
		deleteByNode(h->left);
		deleteByNode(h->right);
		delete h;
	}	
}

int BST::getNumb()
{
	return numb;
}

int BST::getCount()
{
	return count;
}

int BST::select(int x)
{
	searchBynode(root, x, 0);
	return resultKey;
}

int BST::rank(int v)
{
	resultKey = 0;
	searchRank(root, v, 0);
	return resultKey;
}

int BST::searchBynode(Node* h,int rank,int add) {
	if (h == 0)
		return 0;
	else {
		int count = 0;
		count = searchBynode(h->left, rank, add);
		if (count + add == rank) {
			resultKey = h->key;
		}
		count++;
		if (count <= rank) {		
			count=count + searchBynode(h->right, rank, add+count);
		}
		return count;
	}
}

int BST::searchRank(Node*h, int value,int add) {
	if (h == 0)
		return 0;
	else {
		int count = 0;
		count = searchRank(h->left, value, add);
		if (h->key == value) {
			resultKey = count + add;
		}
		count++;
		if (h->key < value) {
			count = count + searchRank(h->right, value, add + count);
		}
		return count;
	}
}
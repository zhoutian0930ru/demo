/**
* C++ Red-Black Tree
*
*/

#ifndef _RED_BLACK_TREE_HPP_
#define _RED_BLACK_TREE_HPP_ 

#include <iomanip>
#include <iostream>
using namespace std;

enum RBTColor { RED, BLACK };

template <class T>
class RBTNode {
public:
	RBTColor color;    
	T key;            
	RBTNode *left;    
	RBTNode *right;    
	RBTNode *parent; 

	RBTNode(T value, RBTColor c, RBTNode *p, RBTNode *l, RBTNode *r) :
		key(value), color(c), parent(), left(l), right(r) {}
};

template <class T>
class RBTree {
private:
	RBTNode<T> *mRoot;    // root

public:
	RBTree();
	~RBTree();

	//get the total path length
	int getCount();
	
	//count the red node
	int searchRed();

	// insert by key
	void insert(T key);

	// remove by key
	void remove(T key);

	// destroy
	void destroy();

	// print
	void print();
private:
	int count;


	//search Red node by Node pointer
	int searchRedByNode(RBTNode<T>* x) const;
	// rotate left
	void leftRotate(RBTNode<T>* &root, RBTNode<T>* x);
	// rotate right
	void rightRotate(RBTNode<T>* &root, RBTNode<T>* y);
	// insert
	void insert(RBTNode<T>* &root, RBTNode<T>* node);
	// nisert fixup
	void insertFixUp(RBTNode<T>* &root, RBTNode<T>* node);
	// remove node
	void remove(RBTNode<T>* &root, RBTNode<T> *node);
	// remove fixup
	void removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent);

	// destroy tree
	void destroy(RBTNode<T>* &tree);

	// print
	void print(RBTNode<T>* tree, T key, int direction);

#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
};

//constructor
template <class T>
RBTree<T>::RBTree() :mRoot(NULL)
{
	mRoot = NULL;
	count = 0;
}

template <class T>
RBTree<T>::~RBTree()
{
	destroy();
}


template <class T>
void RBTree<T>::leftRotate(RBTNode<T>* &root, RBTNode<T>* x)
{
	RBTNode<T> *y = x->right;

	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;

	y->parent = x->parent;

	if (x->parent == NULL)
	{
		root = y; 
	}
	else
	{
		if (x->parent->left == x)
			x->parent->left = y; 
		else
			x->parent->right = y; 
	}
	y->left = x;
	x->parent = y;
}

template <class T>
void RBTree<T>::rightRotate(RBTNode<T>* &root, RBTNode<T>* y)
{
	RBTNode<T> *x = y->left;

	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;

	x->parent = y->parent;

	if (y->parent == NULL)
	{
		root = x;
	}
	else
	{
		if (y == y->parent->right)
			y->parent->right = x;
		else
			y->parent->left = x;
	}

	x->right = y;

	y->parent = x;
}

template <class T>
void RBTree<T>::insertFixUp(RBTNode<T>* &root, RBTNode<T>* node)
{
	RBTNode<T> *parent, *gparent;

	while ((parent = rb_parent(node)) && rb_is_red(parent))
	{
		gparent = rb_parent(parent);

		if (parent == gparent->left)
		{
			{
				RBTNode<T> *uncle = gparent->right;
				if (uncle && rb_is_red(uncle))
				{
					rb_set_black(uncle);
					rb_set_black(parent);
					rb_set_red(gparent);
					node = gparent;
					continue;
				}
			}

			if (parent->right == node)
			{
				RBTNode<T> *tmp;
				leftRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			rb_set_black(parent);
			rb_set_red(gparent);
			rightRotate(root, gparent);
		}
		else
		{
			{
				RBTNode<T> *uncle = gparent->left;
				if (uncle && rb_is_red(uncle))
				{
					rb_set_black(uncle);
					rb_set_black(parent);
					rb_set_red(gparent);
					node = gparent;
					continue;
				}
			}

			if (parent->left == node)
			{
				RBTNode<T> *tmp;
				rightRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}
			rb_set_black(parent);
			rb_set_red(gparent);
			leftRotate(root, gparent);
		}
	}

	rb_set_black(root);
}

template <class T>
void RBTree<T>::insert(RBTNode<T>* &root, RBTNode<T>* node)
{
	RBTNode<T> *y = NULL;
	RBTNode<T> *x = root;

	while (x != NULL)
	{
		count++;
		y = x;
		if (node->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	node->parent = y;
	if (y != NULL)
	{
		if (node->key < y->key)
			y->left = node;
		else
			y->right = node;
	}
	else
		root = node;

	node->color = RED;

	insertFixUp(root, node);
}

template <class T>
void RBTree<T>::insert(T key)
{
	RBTNode<T> *z = NULL;

	if ((z = new RBTNode<T>(key, BLACK, NULL, NULL, NULL)) == NULL)
		return;

	insert(mRoot, z);
}

template <class T>
void RBTree<T>::removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent)
{
	RBTNode<T> *other;

	while ((!node || rb_is_black(node)) && node != root)
	{
		if (parent->left == node)
		{
			other = parent->right;
			if (rb_is_red(other))
			{
				rb_set_black(other);
				rb_set_red(parent);
				leftRotate(root, parent);
				other = parent->right;
			}
			if ((!other->left || rb_is_black(other->left)) &&
				(!other->right || rb_is_black(other->right)))
			{
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (!other->right || rb_is_black(other->right))
				{  
					rb_set_black(other->left);
					rb_set_red(other);
					rightRotate(root, other);
					other = parent->right;
				}
				rb_set_color(other, rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->right);
				leftRotate(root, parent);
				node = root;
				break;
			}
		}
		else
		{
			other = parent->left;
			if (rb_is_red(other))
			{ 
				rb_set_black(other);
				rb_set_red(parent);
				rightRotate(root, parent);
				other = parent->left;
			}
			if ((!other->left || rb_is_black(other->left)) &&
				(!other->right || rb_is_black(other->right)))
			{
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (!other->left || rb_is_black(other->left))
				{ 
					rb_set_black(other->right);
					rb_set_red(other);
					leftRotate(root, other);
					other = parent->left;
				}
				rb_set_color(other, rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->left);
				rightRotate(root, parent);
				node = root;
				break;
			}
		}
	}
	if (node)
		rb_set_black(node);
}

template <class T>
void RBTree<T>::remove(RBTNode<T>* &root, RBTNode<T> *node)
{
	RBTNode<T> *child, *parent;
	RBTColor color;

	if ((node->left != NULL) && (node->right != NULL))
	{

		RBTNode<T> *replace = node;

		replace = replace->right;
		while (replace->left != NULL)
			replace = replace->left;

		if (rb_parent(node))
		{
			if (rb_parent(node)->left == node)
				rb_parent(node)->left = replace;
			else
				rb_parent(node)->right = replace;
		}
		else
			root = replace;

		child = replace->right;
		parent = rb_parent(replace);

		color = rb_color(replace);

		if (parent == node)
		{
			parent = replace;
		}
		else
		{
			if (child)
				rb_set_parent(child, parent);
			parent->left = child;

			replace->right = node->right;
			rb_set_parent(node->right, replace);
		}

		replace->parent = node->parent;
		replace->color = node->color;
		replace->left = node->left;
		node->left->parent = replace;

		if (color == BLACK)
			removeFixUp(root, child, parent);

		delete node;
		return;
	}

	if (node->left != NULL)
		child = node->left;
	else
		child = node->right;

	parent = node->parent;
	color = node->color;

	if (child)
		child->parent = parent;

	if (parent)
	{
		if (parent->left == node)
			parent->left = child;
		else
			parent->right = child;
	}
	else
		root = child;

	if (color == BLACK)
		removeFixUp(root, child, parent);
	delete node;
}

template <class T>
void RBTree<T>::remove(T key)
{
	RBTNode<T> *node;

	if ((node = search(mRoot, key)) != NULL)
		remove(mRoot, node);
}

template <class T>
void RBTree<T>::destroy(RBTNode<T>* &tree)
{
	if (tree == NULL)
		return;

	if (tree->left != NULL)
		return destroy(tree->left);
	if (tree->right != NULL)
		return destroy(tree->right);

	delete tree;
	tree = NULL;
}

template <class T>
void RBTree<T>::destroy()
{
	destroy(mRoot);
}

template <class T>
void RBTree<T>::print(RBTNode<T>* tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)   
			cout << setw(2) << tree->key << "(B) is root" << endl;
		else              
			cout << setw(2) << tree->key << (rb_is_red(tree) ? "(R)" : "(B)") << " is " << setw(2) << key << "'s " << setw(12) << (direction == 1 ? "right child" : "left child") << endl;

		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}

template <class T>
void RBTree<T>::print()
{
	if (mRoot != NULL)
		print(mRoot, mRoot->key, 0);
}

template <class T>
int RBTree<T>::searchRedByNode(RBTNode<T>* x) const
{
	int count = 0;
	if (x == NULL)
		return 0;
	else {
		if (x->color == RED) {
			count = 1;
		}

		return searchRedByNode(x->left) + searchRedByNode(x->right) + count;
	}
}

template <class T>
int RBTree<T>::searchRed()
{
	return searchRedByNode(mRoot);
}

template <class T>
int RBTree<T>::getCount() {
	return count;
}

#endif
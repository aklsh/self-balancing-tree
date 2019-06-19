/*
=========================================================================================
Project - Self Balancing Binary Search Tree
File Name - AVLTree.cpp
Done by - Akilesh Kannan
Created - June 16, 2019
Last Updated - June 19, 2019
References -
            1. ABDUL BARI - 10.1 AVL Tree - Insertion and Rotations - https://www.youtube.com/watch?v=jDM6_TnYIqE
            2. Lecture 12 - CSE 373 - https://courses.cs.washington.edu/courses/cse373/06sp/handouts/lecture12.pdf
=========================================================================================
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include "AVLTree.h"

using namespace std;

AVLTreeNode::AVLTreeNode(int data)
{
	this->data = data;
	this->left = NULL;
	this->right = NULL;
	this->height = 1;
}

AVLTreeNode* AVLTreeNode::rightRotate()
{

/*
           this                         x
           / \      right-rotate       / \
          x  (T3)   ----------->    (T1) this
         / \                              / \
      (T1) (T2)                        (T2) (T3)

*/

	AVLTreeNode *x = this->left;
	AVLTreeNode *T2 = x->right;
	x->right = this;
	this->left = T2;

	this->height = max(getHeight(this->left), getHeight(this->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

	return x;
}

AVLTreeNode* AVLTreeNode::leftRotate()
{

/*
          this                          x
           / \       left-rotate       / \
        (T1)  x      ---------->    this (T3)
             / \                     / \
          (T2) (T3)               (T1) (T2)

*/

	AVLTreeNode* x = this->right;
	AVLTreeNode* T2 = x->left;
	this->right = T2;
	x->left = this;

	this->height = max(getHeight(this->left), getHeight(this->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

	return x;
}

AVLTree::AVLTree()
{
	this->root = NULL;
	size = 0;
}

AVLTreeNode* AVLTree::insertNode(AVLTreeNode *newNode, AVLTreeNode *root)
{
	if(root == NULL)
		return newNode;

	if(newNode->data < root->data)
		root->left = insertNode(newNode, root->left);
	else if(newNode->data > root->data)
		root->right = insertNode(newNode, root->right);
	else
	{
		cout << "duplicate value. Cannot be inserted in the BST." << endl;
		return root;
	}
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

	int bFactor = balanceFactor(root);

	if(bFactor <= 1 && bFactor >= -1)
		return root;
	else
	{
		if(bFactor < -1)
		{
			if(newNode->data > root->right->data)           //right - right inserting
				return root->leftRotate();
			else                                            //right - left inserting
			{
				root->right = root->right->rightRotate();
				return root->leftRotate();
			}
		}
		else if(bFactor > 1)
		{
			if(newNode->data < root->left->data)            //left - left inserting
				return root->rightRotate();
			else                                            //left - right inserting
			{
				root->left = root->left->leftRotate();
				return root->rightRotate();
			}
		}
	}
	return root;
}

AVLTreeNode* AVLTree::getMinNode(AVLTreeNode *root)
{
	AVLTreeNode *temp = root;

	while(temp->left != NULL)
		temp = temp->left;
	return temp;
}

AVLTreeNode* AVLTree::deleteNode(int key, AVLTreeNode *root)
{
	if(root == NULL)
	{
		cout << "The value " << key << " is not present in this BST. So, it cannot be deleted." << endl;
		return root;
	}

	if(key < root->data)
		root->left = deleteNode(key, root->left);
	else if(key > root->data)
		root->right = deleteNode(key, root->right);
	else
	{
	  if(root->left == NULL || root->right == NULL)    // 0 or 1 child case
		{
			if(root->left == NULL)                         // left child not present
				root = root->right;
			else                                           // right child not present
				root = root->left;
		}
		else                                             // 2 children case
		{
			AVLTreeNode *minRight = getMinNode(root->right);
			root->data = minRight->data;
			root->right = deleteNode(minRight->data, root->right);
		}

		int bFactor = balanceFactor(root);

		if(bFactor <= 1 && bFactor >= -1)
			return root;
		else
		{
			if(bFactor < -1)
			{
				if(balanceFactor(root->right) > 0)
				{
					root->right = root->right->rightRotate();
					return root->leftRotate();
				}
				else
					return root->leftRotate();
			}
			else if(bFactor > 1)
			{
				if(balanceFactor(root->left) > 0)
					return root->rightRotate();
				else
				{
					root->left = root->left->leftRotate();
					return root->rightRotate();
				}
			}
		}
	}
	return root;
}

AVLTreeNode* AVLTree::modifyNode(int keyOld, int keyNew, AVLTreeNode* root)
{
	if(searchNode(keyOld, root) == false)
	{
		cout << "A node with the value " << keyOld << " is not present in the tree. Cannot modify a non-existent node." << endl;
		return root;
	}
	else
	{
		//cannot just change the value of given node to new value as BST property
		//may be violated
		root = deleteNode(keyOld, root);
		AVLTreeNode *modify = new AVLTreeNode;
		modify->data = keyNew;
		root = insertNode(modify, root);
	}
  return root;
}

bool searchNode(int key, AVLTreeNode *root)
{
  if(root == NULL)
    return false;
  if(root->data == key)
    return true;
  else
  {
    if(key < root->data)
      return searchNode(key,root->left);
    else
      return searchNode(key,root->right);
  }
  return false;
}

int getHeight(AVLTreeNode *root)
{
	if(root == NULL)                                 //height of leaf = 0
		return 0;
	return root->height;
}

int balanceFactor(AVLTreeNode *root)
{
	if(root == NULL)                                 //balanceFactor of leaf = 0
		return 0;
	return (getHeight(root->left) - getHeight(root->right));
}

void printGraphviz(AVLTreeNode *root, int size)
{
  if(size > 1)
  {
    if (root)
  	{
  		if (root->left)
  		{
  			cout << '"' << root->data << '"';
  			cout << " -> ";
  			cout << '"' << root->left->data << '"';
  			cout << endl;
  			printGraphviz(root->left, size);
  		}
  		if (root->right)
  		{
  			cout << '"' << root->data << '"';
  			cout << " -> ";
  			cout << '"' << root->right->data << '"';
  			cout << endl;
  			printGraphviz(root->right, size);
  		}
  	}
  }
  else
    cout << '"' << root->data << '"';
}

/*
=========================================================================================
Project - Self Balancing Binary Search Tree
File Name - AVLTree.h
Done by - Akilesh Kannan
Created - June 16, 2019
Last Updated - June 19, 2019
References -
            1. ABDUL BARI - 10.1 AVL Tree - Insertion and Rotations - https://www.youtube.com/watch?v=jDM6_TnYIqE
            2. Lecture 12 - CSE 373 - https://courses.cs.washington.edu/courses/cse373/06sp/handouts/lecture12.pdf
=========================================================================================
*/

class AVLTreeNode
{
public:
	int data;
	AVLTreeNode *left;
	AVLTreeNode *right;
	int height;

	AVLTreeNode(int data=0);
	AVLTreeNode* rightRotate();
	AVLTreeNode* leftRotate();
};

class AVLTree
{
public:
	AVLTreeNode *root;
	int size;

	AVLTree();
	AVLTreeNode* insertNode(AVLTreeNode *newNode, AVLTreeNode *root);
  	AVLTreeNode* getMinNode(AVLTreeNode *root);
	AVLTreeNode* deleteNode(int key, AVLTreeNode *root);
	AVLTreeNode* modifyNode(int keyOld, int keyNew, AVLTreeNode *root);
};

bool searchNode(int key, AVLTreeNode *root);
int getHeight(AVLTreeNode *root);
int balanceFactor(AVLTreeNode *root);
void printGraphviz(AVLTreeNode *root, int size=2);

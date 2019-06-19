/*
=========================================================================================
Project - Self Balancing Binary Search Tree
File Name - main.cpp
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
#include <stdlib.h>
#include <stdio.h>
#include "AVLTree.h"

using namespace std;

int main()
{
	system("clear");
	AVLTree myAVL;
	int choice, n, x, newX;
	cout << "Tree is currently empty. Press 1 to start adding elements to tree. Press 0 to exit." << endl;
	takeinchoice: cin >> choice;
	if(choice != 0)
		{
			if(choice != 1)
			{
				cout << "Enter 1 to start adding elements. This is a mandatory step if you do not want to exit." << endl;
				goto takeinchoice;
			}
			else
			{
				cout << "Enter the number of elements you want to add now. You can add more elements later on too.";
				cin >> n;
				myAVL.size = n;
				cout << "Enter " << n << " distinct integer(s), which you want to add to the tree. Separate them by space or enter them on new lines" << endl;
				for(int i = 0; i < n; i++)
				{
					cin >> x;
					AVLTreeNode* temp = new AVLTreeNode;
					temp->data = x;
					myAVL.root = myAVL.insertNode(temp, myAVL.root);
				}
				cout << flush;
				cout << "The tree is now (printed in graphviz form):" << endl;
				cout << "-----------------\n";
				cout << "digraph G {\n";
				printGraphviz(myAVL.root, n);
				cout << "}\n";
				cout << "-----------------\n";
				cout << '\n' << "Press c to continue...";

				//pause func
				do
				{
					for(int i = 0; i < 10; i++);
				}while(cin.get() != 'c');
			}
		}
	else
	{
		system("clear");
		exit(0);
	}

	choice = 1;
	while(myAVL.root && choice!=0)
	{
		system("clear");
		cout << "You have six choices:\n\n 0.exit \n 1.insert an element into the tree \n 2.delete an element from the tree \n 3.search an element within the tree \n 4.modify an element \n 5.print the tree \n\nEnter the corresponding number" << endl;
		cin >> choice;
		if (choice == 0)
			exit(0);
		else if(choice == 1)
		{
			cout << "Enter the element you want to add now. You can add more elements later on too.";
			cin >> x;
			AVLTreeNode* temp = new AVLTreeNode;
			temp->data = x;
			cout << "inserting " << temp->data << " in the tree..." << endl;
			myAVL.root = myAVL.insertNode(temp, myAVL.root);
			myAVL.size++;

			cout << "The tree is now (printed in graphviz form):" << endl;
			cout << "-----------------\n";
			cout << "digraph G {\n";
			printGraphviz(myAVL.root, myAVL.size);
			cout << "}\n";
			cout << "-----------------\n";
		}
		else if(choice == 2)
		{
			cout << "Enter the element you want to delete now. You can delete more elements later on too.";
			cin >> x;
			cout << "deleting " << x << " from the tree..." << endl;
			myAVL.root = myAVL.deleteNode(x, myAVL.root);
			myAVL.size--;

			cout << "The tree is now (printed in graphviz form):" << endl;
			cout << "-----------------\n";
			cout << "digraph G {\n";
			printGraphviz(myAVL.root, myAVL.size);
			cout << "}\n";
			cout << "-----------------\n";

			if(myAVL.root == NULL)
			{
				system("clear");
				cout << "The tree is empty now. You to start all over again. You are now exiting..." << endl;
				break;
			}
		}
		else if(choice == 3)
		{
			cout << "Enter the element you want to search now." << endl;
			cin >> x;
			if(searchNode(x,myAVL.root))
				cout << "Present" << endl;
			else
			 	cout << "Not present" << endl;

			cout << endl;
		}
		else if(choice == 4)
		{
			cout << "Enter the element you want to modify now: " ;
			cin >> x;
			cout << endl;
			cout << "Enter the new value of the element: ";
			cin >> newX;
			cout << "Modifying " << x << " to " << newX << " ...";
			myAVL.root = myAVL.modifyNode(x,newX,myAVL.root);
			cout << endl;

			cout << "The tree is now (printed in graphviz form):" << endl;
			cout << "-----------------\n";
			cout << "digraph G {\n";
			printGraphviz(myAVL.root,myAVL.size);
			cout << "}\n";
			cout << "-----------------\n";
		}
		else if(choice == 5)
		{
			cout << "The tree is now (printed in graphviz form):" << endl;
			cout << "-----------------\n";
			cout << "digraph G {\n";
			printGraphviz(myAVL.root,myAVL.size);
			cout << "}\n";
			cout << "-----------------\n";
		}

		else
			cout << "Enter a valid choice" << endl;
		cout << "Enter 0 for exit, any other number to continue: ";
		cin >> choice;
		if(choice == 0)
			system("clear");
	}

	return 0;
}

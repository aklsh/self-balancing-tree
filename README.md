# Self Balancing BST

### What is a *Self Balancing* BST?
A *self balancing* BST is one which always tries to maintain it's height as minimum as possible. A clearer definition:
>In computer science, a self-balancing (or height-balanced) binary search tree is any node-based binary search tree that 
automatically keeps its height (maximal number of levels below the root) small in the face of 
arbitrary item insertions and deletions <sup>[1](#fn1)</sup>

This repo implements the same with the method called *__AVL Trees__* (Adelson-Velsky-Landis Trees), invented by **Georgy Adelson-Velsky** and  __Evgenii Landis__.

### How to balance a tree?

Any tree can be brought to balance by a number of _rotations_. Rotations are mainly of two types:
##### Left Rotation
```
          this                          x
           / \       left-rotate       / \
        (T1)  x      ---------->    this (T3)
             / \                     / \
          (T2) (T3)               (T1) (T2)
          
    values(T1) < this < values(T2) < x < values(T3)
```

##### Right Rotation
```
           this                         x
           / \      right-rotate       / \
          x  (T3)   ----------->    (T1) this
         / \                              / \
      (T1) (T2)                        (T2) (T3)
    
    values(T1) < x < values(T2) < this < values(T3)
```

*In the above illustrations, _T1_, _T2_, _T3_ are subtrees.* 

In both cases, the new BST formed can be looked at as a _rotation_ about `x`.

### AVL Trees - a quick look
The logic behind the successful working of these trees is that each node has a value associated with, called `balance factor`. It is given by `balance factor = height(left sub-tree) - height(right sub-tree)`. This method tries to make the balance factor of all nodes in the tree to be in the range {-1,0,1}. Height of a `null` subtree is treated as 0. Whenever a node is inserted or deleted, it will check if the new balance factor of all nodes in *all* the subtrees in which the node in question belongs to, still come in the range. If not, it will do a rotation to make the balance factor come back in the range, thus making the tree balanced.

### Organization of files in this repo
* `main.cpp` :  Contains the driver program
* `AVLTree.cpp` : Contains definition of all functions required
* `AVLTree.h` : Contains declaration of classes and functions

### Functions used in the program
|Function Name|Arguments|Description|Returned variable|
|-------------|---------|-----------|-----------------|
|`rightRotate()`| <p align = "center"> nil </p>  | performs right rotation of associated object of type *`AVLTreeNode`*.|pointer to root of rotated node/subtree|
|`leftRotate()`| <p align = "center"> nil </p> | performs left rotation of associated object of type *`AVLTreeNode`*.|pointer to root of rotated node/subtree|
|`insertNode()`|<ul><li>pointer to root of BST</li><li>pointer to node to be inserted</li></ul>| inserts a new node into the given tree.|pointer to root of modified BST|
|`deleteNode()`|<ul><li>pointer to root of BST</li><li>value to be deleted</li></ul>|deletes the given value from the given tree, if present|pointer to root of modified BST|
|`getMinNode()`|pointer to root of BST|finds the node with minimum value in the given BST|pointer to node with minimum value|
|`modifyNode()`|<ul><li>old value</li><li>new value</li><li>pointer to root of BST</li></ul>|modifies node with value *old value* to hold value *new value*|pointer to root of modified BST|
|`searchNode()`|<ul><li>value to be searched for</li><li>pointer to root of BST</li></ul>|searches for node with given value in the given tree|bool value `true` if tree contains node with given value. Else `false`.|
|`getHeight()`|pointer to node of BST|finds the height of given node in the BST|height of the node|
|`balanceFactor`|pointer to node of BST|finds the balance factor of the given node|balance factor of the node|
|`printGraphviz`|<ul><li>pointer to root of BST</li><li>number of nodes in BST</li></ul>|prints the BST in graphviz format|<p align = "center"> nil </p>|

### Usage
* Download / clone this repo with `git clone https://github.com/aklsh/self-balancing-tree` on terminal. This will create a folder named *`self-balancing-tree`*
* `cd` into the folder
* Run with `make`

---
<a name="fn1"><sup>1</sup></a>: <a href = "https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree"> https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree </a>
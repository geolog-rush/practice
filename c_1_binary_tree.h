#ifndef C_1_BINARY_TREE
#define C_1_BINARY_TREE

#include <cstdlib>

// QUESTION:
//
// Part 2 (C tasks):
// 1.	write function which takes pointer to the root of binary tree and returns the high of the tree,
// ...
// 2.	Find depth of binary tree, find diameter of binary tree

struct Node {
    struct Node* l_ptr;
    struct Node* r_ptr;
};

struct Tree {
    struct Node* head;
};

// SOLUTION:
//
// See source file for implementation.

int findHeight(Node* node);
int findDiameter(Node* head, Node* node_1, Node* node_2);

void destruct(Tree* /*tree*/);
Node* add();

#endif /*C_1_BINARY_TREE*/

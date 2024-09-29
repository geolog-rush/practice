#include "c_1_binary_tree.h"

#include <cstdio>
#include <cstdlib>

// Assuming the height is the max number of steps between the head and some node.
// The tree is neither balanced nor sorted.
int findHeight(Node* node) {
    if (!node) return 0;

    int l_height = findHeight(node->l_ptr);
    int r_height = findHeight(node->r_ptr);

    return 1 + (l_height < r_height ? r_height : l_height);
}

// Helper to hold iteration data
struct Iter {
    Node* node_1;
    Node* node_2;
    Node* target;
    int counter;
};

// Assuming the diameter is the number of steps between the nodes.
// The tree is neither balanced nor sorted.
// The complexity is O(n): every node is touched only once.
// If we found one of nodes while iterating a tree then keep iterating
// further while the second node will be found as a target.
static int findNode(Node* head, Iter* iter) {
    if (!head) return false;

    bool no_target_initially = !iter->target;
    if (!iter->target) {
        if (head == iter->node_1)
            iter->target = iter->node_2;
        else if (head == iter->node_2)
            iter->target = iter->node_1;
    }

    if (head == iter->target) return true;
    if (iter->target) ++iter->counter;
    if (findNode(head->l_ptr, iter)) return true;
    if (findNode(head->r_ptr, iter)) return true;
    if (iter->target) no_target_initially ? ++iter->counter : --iter->counter;
    return false;
}

int findDiameter(Node* head, Node* node_1, Node* node_2) {
    if (!head || !node_1 || !node_2 || node_1 == node_2) return 0;

    Iter iter;
    iter.node_1 = node_1;
    iter.node_2 = node_2;
    iter.target = 0;
    iter.counter = 0;
    if (findNode(head, &iter)) return iter.counter;

    return 0;
}

/* Creates new node, for simplicity */
Node* add() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->r_ptr = 0;
    node->l_ptr = 0;
    return node;
}

void destruct(Tree* /*tree*/) {
    // unimplemented
}

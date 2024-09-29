#include "c_1_binary_tree.h"

#include <gtest/gtest.h>

// Simple tree for testing purpose
static Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->head = (Node*)malloc(sizeof(Node));

    /* Example tree:
                  head
                  /  \
              node    node
              /       /   \
           node     node  node
           /  \           /   \
        node  node     node   node
                                 \
                                 node
    */

    (((tree->head->l_ptr = add())->l_ptr = add()))->l_ptr = add();
    tree->head->l_ptr->l_ptr->r_ptr = add();

    ((((tree->head->r_ptr = add())->r_ptr = add()))->r_ptr = add())->r_ptr = add();
    tree->head->r_ptr->l_ptr = add();
    tree->head->r_ptr->r_ptr->l_ptr = add();

    return tree;
}

TEST(BinaryTree, findHeight)
{
    Tree* tree = createTree();
    EXPECT_EQ(findHeight(tree->head), 5);

    // does not increase the overall height
    tree->head->l_ptr->r_ptr = add();
    EXPECT_EQ(findHeight(tree->head), 5);

    // does not increase the overall height but left branch
    EXPECT_EQ(findHeight(tree->head->l_ptr), 3);
    tree->head->l_ptr->l_ptr->l_ptr->l_ptr = add();
    EXPECT_EQ(findHeight(tree->head->l_ptr), 4);
    EXPECT_EQ(findHeight(tree->head), 5);

    // increases by 1 the left branch and the overall height
    tree->head->l_ptr->l_ptr->l_ptr->l_ptr->l_ptr = add();
    EXPECT_EQ(findHeight(tree->head->l_ptr), 5);
    EXPECT_EQ(findHeight(tree->head), 6);

    destruct(tree);
}

TEST(BinaryTree, findDiameter)
{
    Tree* tree = createTree();
    Node* head = tree->head;

    // Belong to one branch
    EXPECT_EQ(findDiameter(head, head, head->l_ptr), 1);
    EXPECT_EQ(findDiameter(head, head, head->r_ptr->l_ptr), 2);
    EXPECT_EQ(findDiameter(head, head->r_ptr->l_ptr, head), 2);
    EXPECT_EQ(findDiameter(head, head->l_ptr, head->l_ptr->l_ptr), 1);
    EXPECT_EQ(findDiameter(head, head->l_ptr, head->l_ptr->l_ptr->l_ptr), 2);

    // Belong to different branches
    EXPECT_EQ(findDiameter(head, head->l_ptr, head->r_ptr), 2);
    EXPECT_EQ(findDiameter(head, head->l_ptr->l_ptr->r_ptr, head->r_ptr->r_ptr->l_ptr), 6);
    EXPECT_EQ(findDiameter(head, head->r_ptr->r_ptr->r_ptr->r_ptr, head->r_ptr->r_ptr->l_ptr), 3);

    destruct(tree);
}

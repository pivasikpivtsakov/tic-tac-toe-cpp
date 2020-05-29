#pragma once

#include "TreeNode.h"

class BinaryTree {
public:
    explicit BinaryTree(int value);

    virtual ~BinaryTree();

    void Insert(int value);

    TreeNode *Search(int value);

private:
    static void Insert(int value, TreeNode *node);

    static TreeNode *Search(int value, TreeNode *node);

    static TreeNode *SearchIfBranchNotEmpty(int value, TreeNode *branch);

    TreeNode *_rootNode = new TreeNode(0);
    int _rootValue = 0;
    TreeNode *_leftChild = nullptr;
    TreeNode *_rightChild = nullptr;
};

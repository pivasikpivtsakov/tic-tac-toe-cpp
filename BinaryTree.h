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

    static TreeNode *
    SearchCommon(int value, int compareToValue, TreeNode *leftBranch, TreeNode *rightBranch, TreeNode *node);

    TreeNode *_rootNode;
    int _rootValue = 0;
    TreeNode *_leftChild = nullptr;
    TreeNode *_rightChild = nullptr;
};

#pragma once

#include "TreeNode.h"

class BinaryTree {
public:
    explicit BinaryTree(int value);

    virtual ~BinaryTree();

    void Insert(int value);
    TreeNode *Search(int value);
private:
    void Insert(int value, TreeNode *node);
    TreeNode *Search(int value, TreeNode *node);
    int _rootValue = 0;
    TreeNode *_leftChild = nullptr;
    TreeNode *_rightChild = nullptr;
};

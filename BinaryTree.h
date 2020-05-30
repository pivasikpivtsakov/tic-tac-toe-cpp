#pragma once

#include "TreeNode.h"

class BinaryTree {
public:
    explicit BinaryTree(int value);

    virtual ~BinaryTree();

    void Insert(int value);

    TreeNode* Search(int value);

private:
    static void Insert(int value, TreeNode*&node);

    static TreeNode* Search(int value, TreeNode* node);

    static TreeNode* SearchIfBranchNotEmpty(int value, TreeNode* branch);

    static TreeNode* SearchCommon(int value, TreeNode* node);

    TreeNode* _rootNode = nullptr;
};

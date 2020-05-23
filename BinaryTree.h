#pragma once

#include "TreeNode.h"

class BinaryTree {
public:
    explicit BinaryTree(int value);

    BinaryTree();

    virtual ~BinaryTree();

    void Insert(int value);
    TreeNode *Search(int value);
private:
    // для рекурсивного удаления узлов дерева
    // я не знаю как сделать рекурсию без дополнительного метода
    void deleteNodeWithChildren(TreeNode *node);
    void Insert(int value, TreeNode *node);
    TreeNode *Search(int value, TreeNode *node);
    int _rootValue;
    TreeNode *_leftChild;
    TreeNode *_rightChild;
};

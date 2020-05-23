#pragma once

#include <vector>

class TreeNode {
public:
    explicit TreeNode(int value);

    int getValue() const;

    void setValue(int value);

    TreeNode *getLeftChild() const;

    void setLeftChild(TreeNode *leftChild);

    TreeNode *getRightChild() const;

    void setRightChild(TreeNode *rightChild);

    TreeNode();

private:
    int _value;
    TreeNode *_leftChild;
    TreeNode *_rightChild;
};

#pragma once

#include <vector>

class TreeNode {
public:
    explicit TreeNode(int value);

    virtual ~TreeNode();

    int getValue() const;

    void setValue(int value);

    TreeNode * getLeftChild() const;

    void setLeftChild(TreeNode *leftChild);

    TreeNode * getRightChild() const;

    void setRightChild(TreeNode *rightChild);

private:
    int _value = 0;
    TreeNode *_leftChild = nullptr;
    TreeNode *_rightChild = nullptr;
};

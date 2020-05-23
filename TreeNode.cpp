#include "TreeNode.h"

TreeNode::TreeNode(int value) : _value(value) {
    _leftChild = nullptr;
    _rightChild = nullptr;
}

TreeNode::TreeNode() {
    _leftChild = nullptr;
    _rightChild = nullptr;
    _value = 0;
}

int TreeNode::getValue() const {
    return _value;
}

void TreeNode::setValue(int value) {
    _value = value;
}

TreeNode *TreeNode::getLeftChild() const {
    return _leftChild;
}

void TreeNode::setLeftChild(TreeNode *leftChild) {
    _leftChild = leftChild;
}

TreeNode *TreeNode::getRightChild() const {
    return _rightChild;
}

void TreeNode::setRightChild(TreeNode *rightChild) {
    _rightChild = rightChild;
}

#include "BinaryTree.h"

BinaryTree::BinaryTree(int value) : _rootValue(value) {
    _leftChild = nullptr;
    _rightChild = nullptr;
}

BinaryTree::BinaryTree() {
    _leftChild = nullptr;
    _rightChild = nullptr;
    _rootValue = 0;
}

BinaryTree::~BinaryTree() {
    deleteNodeWithChildren(_leftChild);
    deleteNodeWithChildren(_rightChild);
}

void BinaryTree::deleteNodeWithChildren(TreeNode *node) {
    if (node != nullptr) {
        if (node->getLeftChild() != nullptr)
            deleteNodeWithChildren(node->getLeftChild());
        if (node->getRightChild() != nullptr)
            deleteNodeWithChildren(node->getRightChild());
        delete node;
    }
}

void BinaryTree::Insert(int value) {
    if (value < _rootValue) {
        if (_leftChild == nullptr)
            _leftChild = new TreeNode(value);
        Insert(value, _leftChild);
    } else if (value > _rootValue) {
        if (_rightChild == nullptr)
            _rightChild = new TreeNode(value);
        Insert(value, _rightChild);
    }
}

TreeNode *BinaryTree::Search(int value) {
    if (value < _rootValue) {
        if (_leftChild == nullptr)
            return nullptr;
        else
            return Search(value, _leftChild);
    } else if (value > _rootValue) {
        if (_rightChild == nullptr)
            return nullptr;
        else
            return Search(value, _rightChild);
    } else
        // кто его потом удалит
        return new TreeNode(_rootValue);
}

void BinaryTree::Insert(int value, TreeNode *node) {
    if (value < node->getValue()) {
        if (node->getLeftChild() == nullptr)
            node->setLeftChild(new TreeNode(value));
        Insert(value, node->getLeftChild());
    } else if (value > node->getValue()) {
        if (node->getRightChild() == nullptr)
            node->setRightChild(new TreeNode(value));
        Insert(value, node->getRightChild());
    }
}

TreeNode *BinaryTree::Search(int value, TreeNode *node) {
    if (value < node->getValue()) {
        if (node->getLeftChild() == nullptr)
            return nullptr;
        else
            return Search(value, node->getLeftChild());
    } else if (value > node->getValue()) {
        if (node->getRightChild() == nullptr)
            return nullptr;
        else
            return Search(value, node->getRightChild());
    } else
        return node;
}

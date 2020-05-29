#include "BinaryTree.h"

BinaryTree::BinaryTree(int value) : _rootValue(value) {
    _rootNode = new TreeNode(value);
}

BinaryTree::~BinaryTree() {
    delete _rootNode;
}

void BinaryTree::Insert(int value) {
    if (value < _rootValue) {
        if (_leftChild == nullptr) {
            _leftChild = new TreeNode(value);
            _rootNode->setLeftChild(_leftChild);
        } else
            Insert(value, _leftChild);
    } else if (value > _rootValue) {
        if (_rightChild == nullptr) {
            _rightChild = new TreeNode(value);
            _rootNode->setRightChild(_rightChild);
        } else
            Insert(value, _rightChild);
    }
}

TreeNode *BinaryTree::Search(int value) {
    return SearchCommon(value, _rootValue, _leftChild, _rightChild, _rootNode);
}

void BinaryTree::Insert(int value, TreeNode *node) {
    if (value < node->getValue()) {
        if (node->getLeftChild() == nullptr)
            node->setLeftChild(new TreeNode(value));
        else
            Insert(value, node->getLeftChild());
    } else if (value > node->getValue()) {
        if (node->getRightChild() == nullptr)
            node->setRightChild(new TreeNode(value));
        else
            Insert(value, node->getRightChild());
    }
}

TreeNode *BinaryTree::Search(int value, TreeNode *node) {
    return SearchCommon(value, node->getValue(), node->getLeftChild(), node->getRightChild(), node);
}

TreeNode *BinaryTree::SearchIfBranchNotEmpty(int value, TreeNode *branch) {
    if (branch == nullptr)
        return nullptr;
    else
        return Search(value, branch);
}

TreeNode *
BinaryTree::SearchCommon(int value, int compareToValue, TreeNode *leftBranch, TreeNode *rightBranch, TreeNode *node) {
    // если искомое число меньше вершины, ищем его в левой ветке
    if (value < compareToValue) {
        return SearchIfBranchNotEmpty(value, leftBranch);
        // если больше - в правой
    } else if (value > compareToValue) {
        return SearchIfBranchNotEmpty(value, rightBranch);
        // если равно - возвращаем вершину
    } else // if (value == node->getValue())
        return node;
}

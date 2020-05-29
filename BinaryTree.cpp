#include "BinaryTree.h"

BinaryTree::BinaryTree(int value) : _rootValue(value) {
    _rootNode->setValue(value);
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
    // если искомое число меньше корня, ищем его в левой ветке
    if (value < _rootValue) {
        return SearchIfBranchNotEmpty(value, _leftChild);
        // если больше - в правой
    } else if (value > _rootValue) {
        return SearchIfBranchNotEmpty(value, _rightChild);
        // если равно - то возвращаем корень
    } else /* if (value == _rootValue) */
        return _rootNode;
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
    // если искомое число меньше вершины, ищем его в левой ветке
    if (value < node->getValue()) {
        return SearchIfBranchNotEmpty(value, node->getLeftChild());
        // если больше - в правой
    } else if (value > node->getValue()) {
        return SearchIfBranchNotEmpty(value, node->getRightChild());
        // если равно - возвращаем вершину
    } else // if (value == node->getValue())
        return node;
}

TreeNode *BinaryTree::SearchIfBranchNotEmpty(int value, TreeNode *branch) {
    if (branch == nullptr)
        return nullptr;
    else
        return Search(value, branch);
}

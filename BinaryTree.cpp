#include "BinaryTree.h"

BinaryTree::BinaryTree(int value) : _rootValue(value) {}

BinaryTree::~BinaryTree() {
    delete _leftChild;
    delete _rightChild;
}

void BinaryTree::Insert(int value) {
    if (value < _rootValue) {
        if (_leftChild == nullptr)
            _leftChild = new TreeNode(value);
        else
            Insert(value, _leftChild);
    } else if (value > _rootValue) {
        if (_rightChild == nullptr)
            _rightChild = new TreeNode(value);
        else
            Insert(value, _rightChild);
    }
}

TreeNode *BinaryTree::Search(int value) {
    // если искомое число меньше корня, ищем его в левой ветке
    if (value < _rootValue) {
        if (_leftChild == nullptr)
            return nullptr;
        else
            return Search(value, _leftChild);
    // если больше - в правой
    } else if (value > _rootValue) {
        if (_rightChild == nullptr)
            return nullptr;
        else
            return Search(value, _rightChild);
    // если равно - то возвращаем корень
    } else /* if (value == _rootValue) */{
        auto *node = new TreeNode(_rootValue);
        node->setLeftChild(_leftChild);
        node->setRightChild(_rightChild);
        return node;
    }
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

// https://ru.wikipedia.org/wiki/%D0%94%D0%B2%D0%BE%D0%B8%D1%87%D0%BD%D0%BE%D0%B5_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE_%D0%BF%D0%BE%D0%B8%D1%81%D0%BA%D0%B0#%D0%9F%D0%BE%D0%B8%D1%81%D0%BA_%D1%8D%D0%BB%D0%B5%D0%BC%D0%B5%D0%BD%D1%82%D0%B0_(FIND)
TreeNode *BinaryTree::Search(int value, TreeNode *node) {
    // если искомое число меньше вершины, ищем его в левой ветке
    if (value < node->getValue()) {
        if (node->getLeftChild() == nullptr)
            return nullptr;
        else
            return Search(value, node->getLeftChild());
    // если больше - в правой
    } else if (value > node->getValue()) {
        if (node->getRightChild() == nullptr)
            return nullptr;
        else
            return Search(value, node->getRightChild());
    // если равно - возвращаем вершину
    // https://github.com/pivasikpivtsakov/tic-tac-toe-cpp/pull/2#discussion_r429669734
    } else // if (value == node->getValue())
        return node;
}

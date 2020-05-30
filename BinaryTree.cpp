#include "BinaryTree.h"

BinaryTree::BinaryTree(int value) {
    _rootNode = new TreeNode(value);
}

BinaryTree::BinaryTree() {
    _rootNode = new TreeNode(0);
}

BinaryTree::~BinaryTree() {
    delete _rootNode;
}

void BinaryTree::Insert(int value) {
    Insert(value, _rootNode);
}

TreeNode* BinaryTree::Search(int value) {
    return SearchCommon(value, _rootNode);
}

void BinaryTree::Insert(int value, TreeNode*&node) {
    if (value < node->getValue()) {
        if (node->getLeftChild() == nullptr)
            node->setLeftChild(new TreeNode(value));
        else {
            auto child = node->getLeftChild();
            Insert(value, child);
        }
    } else if (value > node->getValue()) {
        if (node->getRightChild() == nullptr)
            node->setRightChild(new TreeNode(value));
        else {
            auto child = node->getRightChild();
            Insert(value, child);
        }
    }
}

TreeNode* BinaryTree::Search(int value, TreeNode* node) {
    return SearchCommon(value, node);
}

TreeNode* BinaryTree::SearchIfBranchNotEmpty(int value, TreeNode* branch) {
    if (branch == nullptr)
        return nullptr;
    else
        return Search(value, branch);
}

TreeNode* BinaryTree::SearchCommon(int value, TreeNode* node) {
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

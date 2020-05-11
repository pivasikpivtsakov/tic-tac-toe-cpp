#pragma once

#include "PlayField.h"

class TreeNode {
public:
    explicit TreeNode(PlayField *currentField, TreeNode *ancestorNode = nullptr);

    virtual ~TreeNode();

    bool isTerminal();

    void addChild(TreeNode *childNode);

    TreeNode *operator[](int childIndex);

    int childCount();

    PlayField *value();

private:
    PlayField *const currentField;
    std::vector<TreeNode *> *childNodes = new std::vector<TreeNode *>;
    TreeNode *ancestorNode;

    int childQty();
};

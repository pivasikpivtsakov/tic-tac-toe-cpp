#pragma once

#include "PlayField.h"

class TreeNode {
public:
    explicit TreeNode(PlayField &currentField);

    bool isTerminal() const;

    void addChild(TreeNode &childNode);

    TreeNode &operator[](int childIndex) const;

    int childCount() const;

    PlayField &value() const;

private:
    PlayField &currentField;

    std::vector<std::reference_wrapper<TreeNode>> childNodes;

    // корень дерева предка не имеет
    // оставил указатель чтобы значение могло быть null
    TreeNode *ancestorNode = nullptr;

    int childQty() const;
};

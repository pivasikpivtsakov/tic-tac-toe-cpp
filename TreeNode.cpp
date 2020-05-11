#include <cassert>
#include "TreeNode.h"

TreeNode::TreeNode(PlayField *const currentField, TreeNode *ancestorNode) : currentField(currentField) {
    this->ancestorNode = ancestorNode;
}

bool TreeNode::isTerminal() {
    PlayField::FieldStatus fieldStatus = currentField->checkFieldStatus();
    return fieldStatus != PlayField::FieldStatus::fsNormal;
}

int TreeNode::childQty() {
    return currentField->getEmptyCells().size();
}

void TreeNode::addChild(TreeNode *childNode) {
    assert(childNodes->size() + 1 <= childQty());
    childNode->ancestorNode = this;
    childNodes->emplace_back(childNode);
}

TreeNode *TreeNode::operator[](int childIndex) {
    assert(childIndex < childNodes->size());
    return (*childNodes)[childIndex];
}

int TreeNode::childCount() {
    return childNodes->size();
}

PlayField *TreeNode::value() {
    return currentField;
}

TreeNode::~TreeNode() {
    for (auto &childNode : *childNodes)
        delete childNode;
    delete childNodes;
}

// written by Михаил Чайков, РИ-280001
#include <iostream>
#include "BinaryTree.h"

void CreateMinimalBST(BinaryTree &tree, const int *arrayStartPtr, int startIndex, int endIndex) {
    if (endIndex < startIndex)
        return;
    int middleIndex = (startIndex + endIndex) / 2;
    tree.Insert(arrayStartPtr[middleIndex]);
    CreateMinimalBST(tree, arrayStartPtr, startIndex, middleIndex - 1);
    CreateMinimalBST(tree, arrayStartPtr, middleIndex + 1, endIndex);
}

void SearchAndOutput(BinaryTree &tree, int value){
    auto *foundNode = tree.Search(value);
    if (foundNode == nullptr)
        std::cout << "Node not found, value: " << value << std::endl;
    else
        std::cout << "Found node with value: " << foundNode->getValue() << std::endl;
}

int main() {
    int array[6]{1, 3, 5, 7, 9, 11};
    int startIndex = 0;
    int endIndex = std::size(array) - 1;
    int middleIndex = (startIndex + endIndex) / 2;
    BinaryTree tree = BinaryTree(array[middleIndex]);
    CreateMinimalBST(tree, array, startIndex, endIndex);
    SearchAndOutput(tree, 4);
    SearchAndOutput(tree, 1);
    SearchAndOutput(tree, 3);
    SearchAndOutput(tree, 5);
    SearchAndOutput(tree, 6);
    SearchAndOutput(tree, 7);
    SearchAndOutput(tree, 9);
    SearchAndOutput(tree, 11);
    SearchAndOutput(tree, 100500);
    return 0;
}

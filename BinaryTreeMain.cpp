#include "BinaryTree.h"

void CreateMinimalBST(BinaryTree *tree, const int *arrayStartPtr, int startIndex, int endIndex) {
    if (endIndex < startIndex)
        return;
    int middleIndex = (startIndex + endIndex) / 2;
    tree->Insert(arrayStartPtr[middleIndex]);
    CreateMinimalBST(tree, arrayStartPtr, startIndex, middleIndex - 1);
    CreateMinimalBST(tree, arrayStartPtr, middleIndex + 1, endIndex);
}

int main() {
    int array[7]{1, 2, 3, 4, 5, 6, 7};
    int startIndex = 2;
    int endIndex = std::size(array) - 1;
    int middleIndex = (startIndex + endIndex) / 2;
    auto *tree = new BinaryTree(array[middleIndex]);
    CreateMinimalBST(tree, array, startIndex, endIndex);
    return 0;
}
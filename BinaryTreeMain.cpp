#include <iostream>
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
    int startIndex = 1;
    int endIndex = std::size(array) - 1;
    int middleIndex = (startIndex + endIndex) / 2;
    auto *tree = new BinaryTree(array[middleIndex]);
    CreateMinimalBST(tree, array, startIndex, endIndex);
    // 4 - корень, создали вершину динамически, получили утечку памяти
    // вершина нашлась, см. вывод и дебагер
    auto *foundNode = tree->Search(4);
    std::cout << "Found node with value: " << foundNode->getValue() << std::endl;
    // 6 - вершина, тоже нашлась
    foundNode = tree->Search(6);
    std::cout << "Found node with value: " << foundNode->getValue() << std::endl;
    // 7 - лист дерева, нашёлся
    foundNode = tree->Search(7);
    std::cout << "Found node with value: " << foundNode->getValue() << std::endl;
    return 0;
}

#include <iostream>
#include "Matrix3x3.h"

const int FIXED_MATRIX_SIZE = 3;

void printMatrixFixed(Matrix3x3 &matrix3X3) {
    for (int i = 0; i < FIXED_MATRIX_SIZE; ++i) {
        for (int j = 0; j < FIXED_MATRIX_SIZE; ++j) {
            std::cout << matrix3X3.element(i, j) << ", ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Matrix 3x3" << std::endl;
    auto matrix3X3 = Matrix3x3();
    std::cout << "Filling with random elements" << std::endl;
    matrix3X3.fillRandomElements(-10, 9);
    std::cout << "Randomly filled: " << std::endl;
    printMatrixFixed(matrix3X3);
    for (int i = 0; i < FIXED_MATRIX_SIZE; ++i) {
        std::cout << "Sum of row " << i << ": " << matrix3X3.sumRow(i) << std::endl;
        std::cout << "Max in column " << i << ": " << matrix3X3.maxColumn(i) << std::endl;
        std::cout << "Min in column " << i << ": " << matrix3X3.minColumn(i) << std::endl;
    }
    std::cout << "Sum of principal diagonal " << ": " << matrix3X3.sumPrincipalDiag() << std::endl;
    std::cout << "Sum of secondary diagonal " << ": " << matrix3X3.sumSecondaryDiag() << std::endl;
    std::cout << "Product of principal diagonal " << ": " << matrix3X3.productPrincipalDiag() << std::endl;
    std::cout << "Product of secondary diagonal " << ": " << matrix3X3.productSecondaryDiag() << std::endl;
    return 0;
}

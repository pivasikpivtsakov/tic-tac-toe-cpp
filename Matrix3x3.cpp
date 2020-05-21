#pragma once

#include <xutility>
#include "Matrix3x3.h"
#include <random>

Matrix3x3::Matrix3x3() {
    for (int i = 0; i < std::size(_array); ++i) {
        for (int j = 0; j < std::size(_array[i]); ++j) {
            _array[i][j] = 0;
        }
    }
}

int Matrix3x3::element(const int i, const int j) const {
    return _array[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value) {
    _array[i][j] = value;
}

void Matrix3x3::fillRandomElements(int minVal, int maxVal) {
    // интервал distribution() [minVal, maxVal]
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(minVal, maxVal);
    for (int i = 0; i < std::size(_array); ++i) {
        for (int j = 0; j < std::size(_array[i]); ++j) {
            _array[i][j] = distribution(generator);
        }
    }
}

int Matrix3x3::sumPrincipalDiag() const {
    int sum = 0;
    for (int i = 0; i < std::size(_array); ++i) {
        sum += _array[i][i];
    }
    return sum;
}

int Matrix3x3::sumSecondaryDiag() const {
    int sum = 0;
    for (int i = 0; i < std::size(_array); ++i) {
        sum += _array[i][std::size(_array) - 1 - i];
    }
    return sum;
}

int Matrix3x3::productPrincipalDiag() const {
    int product = 0;
    for (int i = 0; i < std::size(_array); ++i) {
        product *= _array[i][i];
    }
    return product;
}

int Matrix3x3::productSecondaryDiag() const {
    int product = 0;
    for (int i = 0; i < std::size(_array); ++i) {
        product *= _array[i][std::size(_array) - 1 - i];
    }
    return product;
}

int Matrix3x3::sumRow(const int iRow) const {
    int sum = 0;
    for (int i = 0; i < std::size(_array); ++i) {
        sum += _array[iRow][i];
    }
    return sum;
}

int Matrix3x3::minColumn(const int iCol) const {
    int min = INT_MAX;
    for (int i = 0; i < std::size(_array); ++i) {
        if (_array[i][iCol] < min)
            min = _array[i][iCol];
    }
    return min;
}

int Matrix3x3::maxColumn(const int iCol) const {
    int max = INT_MIN;
    for (int i = 0; i < std::size(_array); ++i) {
        if (_array[i][iCol] > max)
            max = _array[i][iCol];
    }
    return max;
}

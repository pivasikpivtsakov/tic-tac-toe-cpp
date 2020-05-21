class Matrix3x3 {
public:
    Matrix3x3();
    int element(int i, int j) const;
    void setElement(int i, int j, int value);
    void fillRandomElements(int minVal, int maxVal);
    int sumPrincipalDiag() const;
    int sumSecondaryDiag() const;
    int productPrincipalDiag() const;
    int productSecondaryDiag() const;
    int sumRow(int iRow) const;
    int minColumn(int iCol) const;
    int maxColumn(int iCol) const;
private:
    int _array[3][3] {};

};

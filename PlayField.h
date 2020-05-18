#pragma once

#include <vector>

class PlayField {
public:
    class CellPos {
    public:
        explicit CellPos(int cellNum);
        CellPos(int row, int column);

        int getRow() const;

        void setRow(int value);

        int getColumn() const;

        void setColumn(int value);

        explicit operator int() const; // 0..8
    private:
        int _row;
        int _column;
    };

    enum CellStatus {
        csEmpty, csCross, csNought
    };

    enum FieldStatus {
        fsInvalid, fsNormal, fsCrossesWin, fsNoughtsWin, fsDraw
    };

    explicit PlayField(std::vector<CellStatus>& field);

    CellStatus operator[](const CellPos &cellPos) const;

    std::vector<CellPos> getEmptyCells() const;

    FieldStatus checkFieldStatus() const;

    PlayField makeMove(const CellPos &cellPos) const;

private:
    // выигрыш по вертикали/горизонтали. Для уменьшения дублирования кода
    bool hasWinInLine(CellStatus player, bool row = false) const;

    bool hasWinInDiagonal(CellStatus player) const;

    // есть ли вообще выигрыш (чтобы не дублировать код отдельно для крестиков и для ноликов)
    bool checkWinStatus(CellStatus player) const;

    // считает клетки заданного типа. Используется в makeMove для определения игрока
    int countCells(CellStatus cellStatus) const;

    static constexpr int fieldSize = 3;

    PlayField operator+(const CellPos &cellPos) const;

    std::vector<CellStatus> &_field;
};


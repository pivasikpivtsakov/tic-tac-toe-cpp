#include <vector>

#pragma once

class PlayField {
public:
    class CellPos {
    public:
        explicit CellPos(int cellNum);

        ~CellPos();

        int getRow() const;

        void setRow(int value);

        int getColumn() const;

        void setColumn(int value);

        explicit operator int() const; // 0..8
    private:
        int _row;
        int _column;
    };

    enum class CellStatus {
        csEmpty, csCross, csNought
    };

    enum class FieldStatus {
        fsInvalid, fsNormal, fsCrossesWin, fsNoughtsWin, fsDraw
    };

    explicit PlayField(std::vector<CellStatus> *field = nullptr);
    virtual ~PlayField();

    CellStatus operator[](CellPos *cellPos) const;

    std::vector<CellPos> getEmptyCells() const;

    FieldStatus checkFieldStatus() const;

    PlayField *makeMove(CellPos *cellPos) const;

private:
    // выигрыш по вертикали/горизонтали. Для уменьшения дублирования кода
    bool hasWinInLine(CellStatus player, bool row = false) const;

    // есть ли вообще выигрыш (чтобы не дублировать код отдельно для крестиков и для ноликов)
    bool checkWinStatus(CellStatus player) const;

    // считает клетки заданного типа. Используется в makeMove для определения игрока
    int countCells(CellStatus cellStatus) const;

    PlayField *operator+(CellPos *cellPos) const;

    std::vector<CellStatus> *_field;
};


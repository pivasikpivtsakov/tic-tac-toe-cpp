#include "PlayField.h"
#include <cassert>

PlayField::CellPos::CellPos(int cellNum) {
    _row = cellNum / 3;
    _column = cellNum % 3;
}

PlayField::CellPos::~CellPos() = default;

int PlayField::CellPos::getRow() const {
    return _row;
}

void PlayField::CellPos::setRow(int value) {
    assert(value >= 0 && value <= 2);
    _row = value;
}

int PlayField::CellPos::getColumn() const {
    return _column;
}

void PlayField::CellPos::setColumn(int value) {
    assert(value >= 0 && value <= 2);
    _column = value;
}

PlayField::CellPos::operator int() const {
    return _column + _row * 3;
}

PlayField::PlayField(std::vector<CellStatus> *field) {
    if (field != nullptr) {
        auto *fieldCopy = new std::vector<CellStatus>(*field);
        _field = fieldCopy;
    } else {
        _field = new std::vector<CellStatus>{
                CellStatus::csEmpty,
                CellStatus::csEmpty,
                CellStatus::csEmpty,
                CellStatus::csEmpty,
                CellStatus::csEmpty,
                CellStatus::csEmpty,
                CellStatus::csEmpty,
                CellStatus::csEmpty,
                CellStatus::csEmpty};
    }
}

PlayField::CellStatus PlayField::operator[](CellPos *cellPos) const {
    return (*_field)[int(*cellPos)];
}

std::vector<PlayField::CellPos> PlayField::getEmptyCells() const {
    std::vector<CellPos> result;
    for (int i = 0; i < _field->size(); ++i)
        if ((*_field)[i] == CellStatus::csEmpty)
            result.emplace_back(CellPos(i));
    return result;
}

bool PlayField::hasWinInLine(PlayField::CellStatus player, bool row) const {
    int multiplier = row ? 1 : 3;
    for (int i = 0; i < 3; ++i) {
        if ((*_field)[i] == player &&
            (*_field)[i + 1 * multiplier] == player &&
            (*_field)[i + 2 * multiplier] == player)
            return true;
    }
    return false;
}

bool PlayField::checkWinStatus(PlayField::CellStatus player) const {
    return (*_field)[0] == player && (*_field)[4] == player && (*_field)[8] == player ||
           (*_field)[2] == player && (*_field)[4] == player && (*_field)[6] == player ||
           hasWinInLine(player) || hasWinInLine(player, true);
}

PlayField::FieldStatus PlayField::checkFieldStatus() const {
    if (checkWinStatus(CellStatus::csCross))
        return FieldStatus::fsCrossesWin;
    if (checkWinStatus(CellStatus::csNought))
        return FieldStatus::fsNoughtsWin;
    int crosses = countCells(CellStatus::csCross);
    int noughts = countCells(CellStatus::csNought);
    if (!(crosses == noughts || crosses == noughts + 1))
        return FieldStatus::fsInvalid;
    if (getEmptyCells().empty())
        return FieldStatus::fsDraw;
    return FieldStatus::fsNormal;
}

PlayField *PlayField::operator+(CellPos *cellPos) const {
    auto *newField = new PlayField(_field);
    (*(newField->_field))[int(*cellPos)] =
            countCells(CellStatus::csCross) > countCells(CellStatus::csNought)
            ? CellStatus::csNought
            : CellStatus::csCross;
    return newField;
}

PlayField *PlayField::makeMove(CellPos *cellPos) const {
    FieldStatus fieldStatus = checkFieldStatus();
    assert((*this)[cellPos] == CellStatus::csEmpty ||
           fieldStatus != FieldStatus::fsCrossesWin ||
           fieldStatus != FieldStatus::fsNoughtsWin ||
           fieldStatus != FieldStatus::fsNormal);
    return *this + cellPos;
}

PlayField::~PlayField() {
    delete _field;
}

int PlayField::countCells(PlayField::CellStatus cellStatus) const {
    int result = 0;
    for (auto &i : *_field) {
        if (i == cellStatus)
            ++result;
    }
    return result;
}

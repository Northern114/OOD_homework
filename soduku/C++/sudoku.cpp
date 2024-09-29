// sudoku.cpp
#include "sudoku.h"

std::set<int> Sudoku::getInference(int row, int col) {
    if (getValue(row, col) != 0) return {};  // 如果这个位置已经有值，直接返回空集

    std::set<int> possibleValues{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 获取当前行的值，排除已存在的值
    for (int val : getRow(row)) {
        possibleValues.erase(val);
    }

    // 获取当前列的值，排除已存在的值
    for (int val : getColumn(col)) {
        possibleValues.erase(val);
    }

    // 获取当前3x3方格的值，排除已存在的值
    for (int val : getBox(row, col)) {
        possibleValues.erase(val);
    }

    return possibleValues;
}

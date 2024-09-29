#ifndef SUDOKU_H
#define SUDOKU_H

#include "grid.h"

class Sudoku : public Grid {
public:
    std::set<int> getInference(int row, int col);  // 获取单元格可能的值（推理值）
};

#endif // SUDOKU_H

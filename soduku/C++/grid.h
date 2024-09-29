// grid.h
#ifndef GRID_H
#define GRID_H

#include <vector>
#include <set>
#include <stdexcept>
class Grid {
protected:
    static const int BOX_SIZE = 3;          // 每个小方格的大小
    static const int GRID_SIZE = BOX_SIZE * BOX_SIZE;  // 整个数独网格的大小
    std::vector<std::vector<int>> grid;     // 用来存储数独的数据

public:
    Grid();  // 构造函数，初始化grid为9x9

    std::vector<int> getRow(int row);       // 获取某一行
    std::vector<int> getColumn(int col);    // 获取某一列
    std::vector<int> getBox(int row, int col); // 获取包含给定单元格的3x3方格
    void setValue(int row, int col, int value);  // 设置单元格的值
    int getValue(int row, int col) const;   // 获取单元格的值
};

#endif // GRID_H

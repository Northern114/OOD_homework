// test_sudoku.cpp
#include <iostream>
#include "sudoku.h"

// 将数独字符串转换为二维数组
void loadSudoku(Sudoku& sudoku, const std::string& sudokuString) {
    if (sudokuString.length() != 81) {
        throw std::invalid_argument("Invalid Sudoku string length");
    }

    for (int i = 0; i < 81; ++i) {
        int row = i / 9;
        int col = i % 9;
        int value = sudokuString[i] - '0';  // 将字符转换为整数
        sudoku.setValue(row, col, value);  // 设置数独中的值
    }
}

// 打印整个数独网格
void printSudoku(Sudoku& sudoku) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            std::cout << sudoku.getValue(row, col) << " ";
        }
        std::cout << std::endl;
    }
}

// 测试数独推理功能
void testSudoku() {
    Sudoku sudoku;
    
    // 数独字符串示例
    std::string sudokuString = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    
    // 将数独字符串加载到 Sudoku 对象中
    loadSudoku(sudoku, sudokuString);
    
    std::cout << "Initial Sudoku Grid:" << std::endl;
    printSudoku(sudoku);

    // 测试 (0, 2) 位置的推理
    std::set<int> possibleValues = sudoku.getInference(0, 2);
    
    std::cout << "\nPossible values for cell (0, 2): ";
    for (int val : possibleValues) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    try {
        testSudoku();
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    return 0;
}


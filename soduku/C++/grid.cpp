// grid.cpp
#include "grid.h"

Grid::Grid() : grid(GRID_SIZE, std::vector<int>(GRID_SIZE, 0)) {}

std::vector<int> Grid::getRow(int row) {
    if (row < 0 || row >= GRID_SIZE) throw std::out_of_range("Invalid row index");
    return grid[row];
}

std::vector<int> Grid::getColumn(int col) {
    if (col < 0 || col >= GRID_SIZE) throw std::out_of_range("Invalid column index");
    std::vector<int> column;
    for (int i = 0; i < GRID_SIZE; ++i) {
        column.push_back(grid[i][col]);
    }
    return column;
}

std::vector<int> Grid::getBox(int row, int col) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) 
        throw std::out_of_range("Invalid row or column index");
    
    std::vector<int> box;
    int startRow = (row / BOX_SIZE) * BOX_SIZE;
    int startCol = (col / BOX_SIZE) * BOX_SIZE;
    for (int i = 0; i < BOX_SIZE; ++i) {
        for (int j = 0; j < BOX_SIZE; ++j) {
            box.push_back(grid[startRow + i][startCol + j]);
        }
    }
    return box;
}

void Grid::setValue(int row, int col, int value) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE)
        throw std::out_of_range("Invalid row or column index");
    if (value < 0 || value > GRID_SIZE) 
        throw std::invalid_argument("Invalid value for Sudoku grid");
    grid[row][col] = value;
}

int Grid::getValue(int row, int col) const {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE)
        throw std::out_of_range("Invalid row or column index");
    return grid[row][col];
}

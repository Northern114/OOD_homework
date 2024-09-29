class Grid:
    BOX_SIZE = 3
    GRID_SIZE = BOX_SIZE * BOX_SIZE

    def __init__(self):
        # 初始化 9x9 的数独网格，默认所有格子都是 0（空）
        self.grid = [[0 for _ in range(self.GRID_SIZE)] for _ in range(self.GRID_SIZE)]

    def get_row(self, row):
        # 获取指定行的数字
        if row < 0 or row >= self.GRID_SIZE:
            raise ValueError("Invalid row index")
        return self.grid[row]

    def get_column(self, col):
        # 获取指定列的数字
        if col < 0 or col >= self.GRID_SIZE:
            raise ValueError("Invalid column index")
        return [self.grid[row][col] for row in range(self.GRID_SIZE)]

    def get_box(self, row, col):
        # 获取包含指定单元格的 3x3 方格的数字
        if row < 0 or row >= self.GRID_SIZE or col < 0 or col >= self.GRID_SIZE:
            raise ValueError("Invalid row or column index")
        
        start_row = (row // self.BOX_SIZE) * self.BOX_SIZE
        start_col = (col // self.BOX_SIZE) * self.BOX_SIZE

        box = []
        for i in range(self.BOX_SIZE):
            for j in range(self.BOX_SIZE):
                box.append(self.grid[start_row + i][start_col + j])
        return box

    def set_value(self, row, col, value):
        # 设置单元格的值
        if row < 0 or row >= self.GRID_SIZE or col < 0 or col >= self.GRID_SIZE:
            raise ValueError("Invalid row or column index")
        if value < 0 or value > self.GRID_SIZE:
            raise ValueError("Invalid value for Sudoku grid")
        self.grid[row][col] = value

    def get_value(self, row, col):
        # 获取单元格的值
        if row < 0 or row >= self.GRID_SIZE or col < 0 or col >= self.GRID_SIZE:
            raise ValueError("Invalid row or column index")
        return self.grid[row][col]


class Sudoku(Grid):
    def get_inference(self, row, col):
        # 如果该位置已经有值，直接返回空集合
        if self.get_value(row, col) != 0:
            return set()
        
        # 用 1-9 初始化可能的值集合
        possible_values = set(range(1, 10))

        # 获取当前行的值并排除已存在的值
        for val in self.get_row(row):
            possible_values.discard(val)

        # 获取当前列的值并排除已存在的值
        for val in self.get_column(col):
            possible_values.discard(val)

        # 获取当前 3x3 方格的值并排除已存在的值
        for val in self.get_box(row, col):
            possible_values.discard(val)

        return possible_values


def load_sudoku(sudoku, sudoku_string):
    # 将长度为 81 的数独字符串转换为二维数组
    if len(sudoku_string) != 81:
        raise ValueError("Invalid Sudoku string length")
    
    for i in range(81):
        row = i // 9
        col = i % 9
        value = int(sudoku_string[i])  # 将字符转换为整数
        sudoku.set_value(row, col, value)


def print_sudoku(sudoku):
    # 打印数独网格
    for row in range(9):
        for col in range(9):
            print(sudoku.get_value(row, col), end=" ")
        print()


def test_sudoku():
    sudoku = Sudoku()
    
    # 数独字符串示例
    sudoku_string = "017903600000080000900000507072010430000402070064370250701000065000030000005601720"
    
    # 将数独字符串加载到 Sudoku 对象中
    load_sudoku(sudoku, sudoku_string)
    
    print("Initial Sudoku Grid:")
    print_sudoku(sudoku)

    # 测试 (0, 2) 位置的推理
    possible_values = sudoku.get_inference(0, 2)
    
    print("\nPossible values for cell (0, 2):", possible_values)


if __name__ == "__main__":
    test_sudoku()


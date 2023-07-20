#include <iostream>
#include <vector>

void shiftOuterSquares(std::vector<std::vector<int>>& grid) {
    int n = grid.size();

    // Shift top row (left to right)
    for (int j = 0; j < n - 1; j++) {
        int temp = grid[0][j];
        grid[0][j] = grid[0][j + 1];
        grid[0][j + 1] = temp;
    }

    // Shift right column (top to bottom)
    for (int i = 0; i < n - 1; i++) {
        int temp = grid[i][n - 1];
        grid[i][n - 1] = grid[i + 1][n - 1];
        grid[i + 1][n - 1] = temp;
    }

    // Shift bottom row (right to left)
    for (int j = n - 1; j > 0; j--) {
        int temp = grid[n - 1][j];
        grid[n - 1][j] = grid[n - 1][j - 1];
        grid[n - 1][j - 1] = temp;
    }

    // Shift left column (bottom to top)
    for (int i = n - 1; i > 0; i--) {
        int temp = grid[i][0];
        grid[i][0] = grid[i - 1][0];
        grid[i - 1][0] = temp;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> grid(n, std::vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> grid[i][j];
        }
    }

    shiftOuterSquares(grid);

    // Print the resulting grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

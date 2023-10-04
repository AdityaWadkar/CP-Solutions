#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int numDistinctIslands(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::unordered_set<std::string> island_shapes;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    std::string shape;
                    dfs(grid, i, j, i, j, shape);
                    island_shapes.insert(shape);
                }
            }
        }

        return island_shapes.size();
    }

private:
    void dfs(std::vector<std::vector<int>>& grid, int original_i, int original_j, int i, int j, std::string& shape) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] != 1) {
            return;
        }

        grid[i][j] = 0; // Mark the visited cell as 0 (visited)

        // Store the relative coordinates of the cell with respect to the starting cell
        shape += std::to_string(i - original_i) + std::to_string(j - original_j);

        // DFS in all four directions (up, down, left, right)
        dfs(grid, original_i, original_j, i - 1, j, shape);
        dfs(grid, original_i, original_j, i + 1, j, shape);
        dfs(grid, original_i, original_j, i, j - 1, shape);
        dfs(grid, original_i, original_j, i, j + 1, shape);
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };

    int numDistinct = solution.numDistinctIslands(grid);
    std::cout << "Number of distinct islands: " << numDistinct << std::endl;

    return 0;
}

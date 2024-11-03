#include<iostream>
#include<vector>
#include<math.h>
class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int rows = grid.size(), columns = grid[0].size();
        if (rows == 0 || columns == 0) {
            return 0;
        }
        std::vector<std::vector<int>> dep (rows, std::vector<int> (columns));
        dep[0][0] = grid[0][0];
        for (int i = 1; i < rows; i++) {
            dep[i][0] = dep[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < columns; i++) {
            dep[0][i] = dep[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                dep[i][j] = std::min(dep[i - 1][j], dep[i][j - 1]) + grid[i][j];
            }
        }
        return dep[rows - 1][columns - 1];
    }
};
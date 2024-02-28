#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (unsigned int row = 0; row < grid.size(); ++row) {
            for (unsigned int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1) {
                    int area;

                    area = findArea(grid, row, col);
                    if (area > maxArea)
                        maxArea = area;
                }
            }
        } 

        return (maxArea);
    }

private:
    int    findArea(vector<vector<int>>& grid, int row, int col) {
        if (row == grid.size() || col == grid[0].size() || 
                min(row, col) < 0 || grid[row][col] == 0)
            return (0);

        int count = 1;

        grid[row][col] = 0;
        count += findArea(grid, row + 1, col);
        count += findArea(grid, row, col + 1);
        count += findArea(grid, row - 1, col);
        count += findArea(grid, row, col - 1);
        return (count);
    }
};
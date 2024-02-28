#include <iostream>
#include <vector>

using namespace std;

class Solution {
    /*
        1. I can modify the grid. 

        Strategy:
            - "Big traverse" through the grid
            - If I find a land
                - run dfs() algorithm to check if you are surrounded. 
                - after that empty the land. Remove all the land
    */

public:
    int numIslands(vector<vector<char>>& grid) {

        int count = 0;

        for (unsigned int row = 0; row < grid.size(); ++row) {
            for (unsigned int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == '1') {
                    freeTheLand(grid, row, col);
                    count++;
                }
            }
        }
        return (count);
    }

private:
    void    freeTheLand(vector<vector<char>>& grid, int row, int col) { // DFS
        if (row == grid.size() || col == grid[0].size() || 
                min(row, col) < 0 || grid[row][col] == '0')
            return;

        grid[row][col] = '0';
        freeTheLand(grid, row + 1, col);
        freeTheLand(grid, row, col + 1);
        freeTheLand(grid, row - 1, col);
        freeTheLand(grid, row, col - 1);
    }
};
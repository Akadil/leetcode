#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        ROW = grid.size();
        COLUMN = grid[0].size();    // Consider an edge case with no rows
        
        set<string> visit;
        return (dfs(grid, 0, 0, visit));
    }

private:
    int ROW;
    int COLUMN;

    int dfs(vector<vector<int>>& grid, int row, int col, set<string>& visited) {
        if (min(row, col) < 0 || row == ROW || col == COLUMN || grid[row][col] == 1 || 
                visited.find(to_string(row) + "," + to_string(col)) != visited.end())
            return (0);
        if (row == ROW - 1 && col == COLUMN - 1)
            return (1);

        int count = 0;

        // Save the data about visited cells
        visited.insert(to_string(row) + "," + to_string(col));
        
        // Run the DFS algorithm
        count += dfs(grid, row + 1, col, visited);
        count += dfs(grid, row, col + 1, visited);
        count += dfs(grid, row - 1, col, visited);
        count += dfs(grid, row, col - 1, visited);
        
        visited.erase(to_string(row) + "," + to_string(col));

        return (count);
    }
};

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLUMNS = grid[0].size();
        int num_fresh = 0;
        queue<pair<int, int>>   rotten;

        // Analyze the grid
        for (unsigned int i = 0; i < ROWS; ++i) {
            for (unsigned int j = 0; j < COLUMNS; ++j) {
                if (grid[i][j] == 1)
                    num_fresh++;
                else if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }

        int minutes = 0;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (rotten.empty() == false && num_fresh > 0) {
            int size = rotten.size();
            for (unsigned int i = 0; i < size; ++i) {
                pair<int, int> current = rotten.front();
                rotten.pop();

                for (auto dir : directions) {
                    int row = current.first + dir.first;
                    int col = current.second + dir.second;

                    if (row >= 0 && row < ROWS && col >= 0 && col < COLUMNS && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        rotten.push({row, col});
                        num_fresh--;
                    }
                }
            }
            minutes++;
        }
        return (num_fresh == 0 ? minutes : -1);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << sol.orangesRotting(grid) << endl;
    return 0;
}
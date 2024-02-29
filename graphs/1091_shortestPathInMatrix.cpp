#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLUMNS = grid[0].size();

        vector<vector<int>> visited(ROWS, vector<int>(COLUMNS));
        queue<pair<int, int>>   queue;

        if (grid[0][0] == 0)
            queue.push(pair<int, int>(0, 0));
        visited[0][0] = 1;

        int length = 1;
        while (queue.empty() == false) {
            int queueLength = queue.size();
            for (unsigned int j = 0; j < queueLength; ++j) {

                pair<int, int>  currPair = queue.front();
                queue.pop();

                int row = currPair.first, col = currPair.second;
                if (row == ROWS - 1 && col == COLUMNS - 1)
                    return length;

                int neighbours[8][2] = {{row + 1, col}, {row, col + 1},
                                        {row - 1, col}, {row, col - 1},
                                        {row - 1, col - 1}, {row - 1, col + 1},
                                        {row + 1, col - 1}, {row + 1, col + 1}};

                for (unsigned int i = 0; i < 8; ++i) {
                    int newRow = neighbours[i][0], newCol = neighbours[i][1];

                    if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLUMNS) {
                        if (visited[newRow][newCol] == 0 && grid[newRow][newCol] == 0) {
                            queue.push(pair<int, int>(newRow, newCol));
                            visited[newRow][newCol] = 1;
                        }
                    }
                }
            }
            length++;
        }
        return -1;
    }
};
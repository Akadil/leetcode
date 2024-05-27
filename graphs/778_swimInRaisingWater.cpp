#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
// typename pair<int, pair<int,int>> intToCoor;

public:
    int swimInWater(vector<vector<int>>& grid) {
        // the amount of water in given coordinate
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> minHeap;
        int height = 0;

        minHeap.push({grid[0][0], {0, 0}});
        while (!minHeap.empty()) {
            pair<int, pair<int,int>>       node = minHeap.top();
            int             level = node.first;
            pair<int,int>   coor = node.second;
            
            minHeap.pop();
            grid[coor.first][coor.second] = -1;
            if (height < level)
                height = level;
            // std::cout << "[" << coor.first << "," << coor.second << "] ";
            // std::cout << "Value: " << level << ", height: " << height << std::endl;
            if (coor.first == grid.size() - 1 && coor.second == grid.size() - 1)
                break;

            vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (vector<int> dir : dirs) {
                int row = coor.first + dir[0];
                int col = coor.second + dir[1];

                if (row > -1 && row < grid.size() && col > -1 && col < grid.size()) {
                    if (grid[row][col] != -1) {
                        minHeap.push({grid[row][col], {row, col}});
                    }
                }
            }
        }
        return (height);
    }
};
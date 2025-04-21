#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
    public:
        int m;
        int n;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int minimumEffortPath(vector<vector<int>>& heights) {
            m = heights.size();
            n = heights[0].size();
            int left = 0;
            int right = 0;
            for (vector<int>& row: heights) {
                for (int num: row) {
                    right = max(right, num);
                }
            }
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (check(mid, heights)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            return left;
        }
        
        bool check(int effort, vector<vector<int>>& heights) {
            vector<vector<bool>> seen(m, vector<bool>(n, false));
            stack<pair<int, int>> stack;
            seen[0][0] = true;
            stack.push(pair(0, 0));
            
            while (!stack.empty()) {
                auto [row, col] = stack.top();
                stack.pop();
                if (row == m - 1 && col == n - 1) {
                    return true;
                }
                
                for (vector<int>& direction: directions) {
                    int nextRow = row + direction[0], nextCol = col + direction[1];
                    if (valid(nextRow, nextCol) && !seen[nextRow][nextCol]) {
                        if (abs(heights[nextRow][nextCol] - heights[row][col]) <= effort) {
                            seen[nextRow][nextCol] = true;
                            stack.push(pair(nextRow, nextCol));
                        }
                    }
                }
            }
            
            return false;
    
        }
        
        bool valid(int row, int col) {
            return 0 <= row && row < m && 0 <= col && col < n;
        }
    };
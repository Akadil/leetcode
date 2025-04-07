/**
 * Problem: 695. Max Area of Island
 *
 * Given a 2D grid of 0s and 1s, where 1 represents land and 0 represents water,
 * return the size of the largest connected area of land (island).
 *
 * Approach:
 * - Use DFS to explore connected land components.
 * - Track visited cells with a 2D "visited" matrix to avoid cycles.
 * - Check all 4 directions from each land cell (up, down, left, right).
 */

 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 class Solution {
 public:
     /**
      * Returns the size of the largest island (connected component of 1s).
      *
      * @param grid - 2D grid representing land and water
      * @return max area of any island
      */
     int maxAreaOfIsland(vector<vector<int>>& grid) {
         int n = grid.size();
         int m = grid[0].size();
         visited = vector<vector<bool>>(n, vector<bool>(m, false));
 
         int max_area = 0;
 
         // Explore each cell in the grid
         for (int i = 0; i < n; ++i) {
             for (int j = 0; j < m; ++j) {
                 if (!visited[i][j] && grid[i][j] == 1) {
                     max_area = max(max_area, dfs(grid, i, j));
                 }
             }
         }
 
         return max_area;
     }
 
 private:
     vector<vector<bool>> visited;
 
     // Directions: down, up, right, left
     const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
 
     /**
      * DFS to compute area of island starting at (i, j).
      *
      * @param grid - reference to the input grid
      * @param i - current row
      * @param j - current column
      * @return area of the connected island
      */
     int dfs(const vector<vector<int>>& grid, int i, int j) {
         visited[i][j] = true;
         int area = 1;
 
         for (const auto& [dx, dy] : directions) {
             int ni = i + dx;
             int nj = j + dy;
 
             if (is_valid(ni, nj, grid) && !visited[ni][nj] && grid[ni][nj] == 1) {
                 area += dfs(grid, ni, nj);
             }
         }
 
         return area;
     }
 
     /**
      * Checks whether the coordinates are within grid bounds.
      */
     bool is_valid(int i, int j, const vector<vector<int>>& grid) {
         return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
     }
 };
 
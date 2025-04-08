class Solution {
    public:
        /**
         * @brief Updates each cell in the matrix with the distance to the nearest 0.
         * 
         * Given a binary matrix (0s and 1s), this function returns a matrix where each cell
         * contains the distance to the nearest 0. The distance is measured in number of steps
         * through adjacent cells (up/down/left/right).
         * 
         * @param mat Input 2D grid of integers (0s and 1s)
         * @return A 2D grid where each cell contains the distance to the nearest 0
         */
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int rows = mat.size();         // Number of rows
            int cols = mat[0].size();      // Number of columns
    
            // Queue for BFS, holds coordinates of cells
            queue<pair<int, int>> q;
    
            // Distance matrix initialized to -1 (meaning unvisited)
            vector<vector<int>> dist(rows, vector<int>(cols, -1));
    
            // Step 1: Enqueue all 0-cells and initialize their distance to 0
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (mat[i][j] == 0) {
                        q.push({i, j});     // Start BFS from all 0s simultaneously
                        dist[i][j] = 0;     // Distance to itself is 0
                    }
                }
            }
    
            // Step 2: Define movement directions (up, down, left, right)
            vector<pair<int, int>> directions = {
                {1, 0}, {-1, 0}, {0, 1}, {0, -1}
            };
    
            // Step 3: Perform BFS to compute distances
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
    
                // Explore all 4 directions
                for (auto& [dx, dy] : directions) {
                    int nx = x + dx;   // New row
                    int ny = y + dy;   // New column
    
                    // Check bounds and whether the cell is unvisited
                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && dist[nx][ny] == -1) {
                        dist[nx][ny] = dist[x][y] + 1;  // Update distance from the nearest 0
                        q.push({nx, ny});              // Enqueue for further exploration
                    }
                }
            }
    
            // Return the matrix of distances
            return dist;
        }
    };
    
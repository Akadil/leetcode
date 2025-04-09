class Solution {
    public:
        // Main function to compute the minimum number of moves to reach the final cell
        int snakesAndLadders(vector<vector<int>>& board) {
            // Store the board and its size
            this->board = board;
            board_size = board.size();
    
            // Start BFS from cell 1 (the beginning of the board)
            queue<int> queue({1});
            int ans = 0; // Number of moves taken
    
            // A boolean vector to track whether a cell has been visited
            vector<bool> not_seen(board_size * board_size, true);
            not_seen[0] = false; // Mark the starting cell as visited
    
            // BFS traversal
            while (!queue.empty()) {
                int curr_level_length = queue.size(); // All positions we can reach in this turn
    
                for (int i = 0; i < curr_level_length; ++i) {
                    int curr = queue.front();
                    queue.pop();
    
                    // If we've reached the final cell, return the number of moves
                    if (curr == board_size * board_size)
                        return ans;
    
                    // Try all possible dice rolls (1 to 6)
                    for (int j = 1; j <= 6; ++j) {
                        int next = curr + j;
                        // Only consider valid cells
                        if (next <= board_size * board_size) {
                            // Get the final position after applying snake or ladder (if any)
                            int new_position = get_position(next);
                            // If we haven't visited this position, add it to the queue
                            if (not_seen[new_position - 1]) {
                                not_seen[new_position - 1] = false;
                                queue.push(new_position);
                            }
                        }
                    }
                }
                ans++; // Increase move count after exploring one BFS level
            }
    
            // If the destination is unreachable
            return -1;
        }
    
    private:
        vector<vector<int>> board;  // The game board
        int board_size;             // Board is of size N x N
    
        // Converts a 1-based cell number to its actual position on the 2D board,
        // taking into account the zigzag numbering
        int get_position(int cell) {
            // Calculate row index from bottom to top
            int row = board_size - 1 - (cell - 1) / board_size;
            // Calculate column index depending on the row's direction (left-to-right or right-to-left)
            int col = (cell - 1) % board_size;
            if (((cell - 1) / board_size) % 2 == 1)
                col = board_size - 1 - col;
    
            // If no snake or ladder, return the cell itself
            // Otherwise, return the destination cell
            return (board[row][col] == -1) ? cell : board[row][col];
        }
    };
    
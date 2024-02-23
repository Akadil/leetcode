#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));

        backtracking(n, 0);
        return (returner);
    }

private:
    vector<vector<string>>  returner;
    vector<string>          board;

    void    backtracking(int n, int row) {
        
        // Base case with n == row
        if (row == n) {
            returner.push_back(board);
            return ;
        }

        // Traverse through columns
        for (unsigned int i = 0; i < n; ++i) {
            placeQueen(row, i);

            if (isValidMap(row, i, n) == true) {
                backtracking(n, row + 1);
            }

            unplaceQueen(row, i);
        }
    }

    bool    isValidMap(int row, int column, int n) {

        // Traverse through previous rows
        for (int i = 0; i < row; i++) {
            
            // Check the column
            if (board[i][column] == 'Q')
                return (false);

            // Check the positive diagonal
            if (column + row - i < n && board[i][column + row - i] == 'Q')
                return (false);

            // Check the negative diagonal
            if (column - row + i >= 0 && board[i][column - row + i] == 'Q')
                return (false);    
        }
        return (true);
    }

    void    placeQueen(int row, int column) {
        board[row][column] = 'Q';
    }

    void    unplaceQueen(int row, int column) {
        board[row][column] = '.';
    }
};
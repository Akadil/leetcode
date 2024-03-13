#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        ROW = board.size();
        COLUMN = board[0].size();
        
        for (unsigned int i = 0; i < ROW; ++i) {
            for (unsigned int j = 0; j < COLUMN; ++j) {
                if (dfs(board, i, j, word, 0) == true)
                    return (true);
            }
        }
        return (false);
    }

private:
    int ROW;
    int COLUMN;

    bool    dfs(vector<vector<char>>& board, int row, int col, string& word, int index) {
        if (index == word.size())
            return true;
        if (row < 0 || col < 0 || row >= ROW || col >= COLUMN  || board[row][col] != word[index])
            return false;

        board[row][col] = '#';

        if (dfs(board, row + 1, col, word, index + 1)
            || dfs(board, row - 1, col, word, index + 1)
            || dfs(board, row, col + 1, word, index + 1)
            || dfs(board, row, col - 1, word, index + 1)) {
            return (true);
        }

        board[row][col] = word[index];
        return (false);
    }
};

int main(void) {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ASA";
    Solution sol;
    cout << sol.exist(board, word) << endl;
    return 0;
}
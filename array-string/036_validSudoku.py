class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        squares = {}
        for i in range(9):
            rows = set()
            for j in range(9):
                if board[i][j] == '.':
                    continue
                if board[i][j] in rows:
                    return False
                rows.add(board[i][j])
                if (i / 3, j / 3) not in squares.keys():
                    squares[(i / 3, j / 3)] = [board[i][j]]
                else:
                    if board[i][j] != '.' and board[i][j] in squares[(i / 3, j / 3)]:
                        return False
                    else:
                        squares[(i / 3, j / 3)].append(board[i][j])            
        for j in range(9):
            columns = set()
            for i in range(9):
                if board[i][j] == '.':
                    continue
                if board[i][j] in columns:
                    return False
                columns.add(board[i][j])
        return True

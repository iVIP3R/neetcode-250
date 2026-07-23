class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<int> row;
            unordered_set<int> column;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (row.count(board[i][j]) == 1) return false;
                    row.insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    if (column.count(board[j][i]) == 1) return false;
                    column.insert(board[j][i]);
                }
            }
        }

        int box = 0, row = -3, column = 0;
            for (int i = 0; i < 9; i++, box++) {
                unordered_set<int> subbox;
                column += 3;
                if (box % 3 == 0) {
                    column = 0;
                    row += 3;
                }
                for (int j = 0; j < 3; j++) {
                    for (int z = 0; z < 3; z++) {
                        int currRow = j + row;
                        int currCol = z + column;
                        if (board[currRow][currCol] != '.') {
                            if (subbox.count(board[currRow][currCol]) == 1) return false;
                            subbox.insert(board[currRow][currCol]);
                        }
                    }
                }
            }
        return true;
    }
};
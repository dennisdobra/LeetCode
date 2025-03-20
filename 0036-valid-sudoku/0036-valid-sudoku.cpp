class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (i % 3 == 0 && j % 3 == 0) {
                    // check square
                    if (!checkSquare(board, i, j)) {
                        return false;
                    }
                }

                if (board[i][j] == '.') continue;

                if (!checkLineAndCol(board, i, j, board[i][j] - '0')) {
                    return false;
                }
            }
        }

        return true;
    }

    bool checkLineAndCol(vector<vector<char>>& board, int row, int col, int value) {
        // check on row
        int cnt = 0;
        for (int i = 0; i < board[0].size(); i++) {
            if (board[row][i] == '.') continue;

            if (board[row][i] - '0' == value) {
                cnt++;

                if (cnt > 1) return false;
            }
        }

        // check on column
        cnt = 0;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == '.') continue;

            if (board[i][col] - '0' == value) {
                cnt++;

                if (cnt > 1) return false;
            }
        }

        return true;
    }

    bool checkSquare(vector<vector<char>>& board, int i, int j) {
        unordered_set<int> seen;
        for (int k = i; k < i + 3; k++) {
            for (int l = j; l < j + 3; l++) {
                if (board[k][l] == '.') {
                    continue;
                }

                if (!seen.insert(board[k][l] - '0').second) {
                    return false;
                }
            }
        }

        return true;
    }
};
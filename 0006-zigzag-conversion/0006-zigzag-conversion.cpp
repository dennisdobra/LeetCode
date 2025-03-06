class Solution {
public:
    string convert(string s, int numRows) {
        int numCols = 1000;

        vector<vector<char>> mat(numRows, vector<char>(numCols, '*'));

        int idx = 0;
        int col = 0;
        while (idx < s.size()) {
            for (int i = 0; i < numRows && idx < s.size(); i++) {
                mat[i][col] = s[idx];
                idx++;
            }

            for (int i = numRows - 2; i > 0 && idx < s.size(); i--) {
                col++;
                mat[i][col] = s[idx];
                idx++;
            }
            col++;
        }

        string result = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (mat[i][j] != '*') {
                    result += mat[i][j];
                }
            }
        }

        return result;
    }
};
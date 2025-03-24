class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    cout << "i = " << i << ", j = " << j << endl;
                    // set row
                    for (int col = 0; col < matrix[0].size(); col++) {
                        if (matrix[i][col] != 0) {
                            matrix[i][col] = INT_MAX;
                        }
                    }

                    for (int row = 0; row < matrix.size(); row++) {
                        if (matrix[row][j] != 0) {
                            matrix[row][j] = INT_MAX;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == INT_MAX) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
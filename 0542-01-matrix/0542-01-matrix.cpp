class Solution {
public:
    int m;
    int n;
    vector<vector<int>> grid;
    vector<vector<bool>> seen;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        this->grid = mat;
        m = mat.size();
        n = mat[0].size();

        queue<vector<int>> queue;
        vector<vector<bool>> seen(m, vector<bool>(n, false));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 0) {
                    queue.push({row, col, 0});
                    seen[row][col] = true;
                }
            }
        }

        // start a BFS from every '0' cell
        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();

            int row = curr[0], col = curr[1], steps = curr[2];

            for (vector<int>& dir : directions) {
                int nextRow = row + dir[0];
                int nextCol = col + dir[1];

                if (valid(nextRow, nextCol) && seen[nextRow][nextCol] == false) {
                    seen[nextRow][nextCol] = true;
                    queue.push({nextRow, nextCol, steps + 1});
                    mat[nextRow][nextCol] = steps + 1;
                }
            }
        }
        
        return mat;
    }

    bool valid(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
};
class Solution {
public:
    int m;
    int n;
    vector<vector<bool>> seen;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int numEnclaves(vector<vector<int>>& grid) {
        // start a BFS from all cells on the border of the grid
        // with a value of 1 and mark them as visited
        // then, iterate through the matrix and count all cells with a value of
        // one that have not been visisted
        m = grid.size();
        n = grid[0].size();

        seen = vector(m, vector<bool>(n, false));

        queue<pair<int, int>> queue;
        
        // coloana 0 si coloana n - 1
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && seen[i][0] == false) {
                queue.push({i, 0});
                seen[i][0] = true;
            }

            if (grid[i][n - 1] == 1 && seen[i][n - 1] == false) {
                queue.push({i, n - 1});
                seen[i][n - 1] = true;
            }
        }

        // linia 0 si linia m - 1
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1 && seen[0][i] == false) {
                queue.push({0, i});
                seen[0][i] = true;
            }

            if (grid[m - 1][i] == 1 && seen[m - 1][i] == false) {
                queue.push({m  - 1, i});
                seen[m - 1][i] = true;
            }
        }

        while (!queue.empty()) {
            auto [currRow, currCol] = queue.front();
            queue.pop();

            for (vector<int> dir : directions) {
                int newRow = currRow + dir[0];
                int newCol = currCol + dir[1];

                if (isValid(newRow, newCol) && grid[newRow][newCol] == 1) {
                    queue.push({newRow, newCol});
                    seen[newRow][newCol] = true;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && seen[i][j] == false) {
                    count++;
                }
            }
        }

        return count;
    }

    bool isValid(int row, int col) {
        if (row >= 0 && row < m && col >= 0 && col < n && seen[row][col] == false) {
            return true;
        }

        return false;
    }
};
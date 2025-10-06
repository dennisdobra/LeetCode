class Solution {
public:
    int n;
    vector<vector<int>> grid;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return -1;

        // initializari
        this->grid = grid;
        n = grid.size();
        vector<vector<bool>> seen(n, vector<bool>(n, false));

        queue<pair<int, int>> queue;
        seen[0][0] = true;
        queue.push({0, 0});

        int level = 0;
        while (!queue.empty()) {
            int nodesInQueue = queue.size();

            level++;
            for (int i = 0; i < nodesInQueue; i++) {
                auto [row, col] = queue.front();
                queue.pop();

                // check if we have reached bottom-right corner
                if (row == n - 1 && col == n - 1) return level;

                // check the neighbours
                for (vector<int> dir : directions) {
                    int nextRow = row + dir[0];
                    int nextCol = col + dir[1];

                    if (valid(nextRow, nextCol) && seen[nextRow][nextCol] == false) {
                        seen[nextRow][nextCol] = true;
                        queue.push({nextRow, nextCol});
                    }
                }
            }
        }

        return -1;
    }

    bool valid(int row, int col) {
        return row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0;
    }
};
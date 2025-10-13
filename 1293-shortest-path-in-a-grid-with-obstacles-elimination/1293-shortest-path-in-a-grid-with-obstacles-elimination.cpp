class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> seen(m, vector<int>(n, -1));
        // for seen, we can save one dimension for "remain"
        // there is no point in going back to a square we already
        // visited, but with less remaining removals

        queue<vector<int>> queue;
        queue.push({0, 0, k, 0});

        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();

            int row = curr[0], col = curr[1], remain = curr[2], steps = curr[3];

            // check if we have reached the destination
            if (row == m - 1 && col == n - 1) return steps;

            for (vector<int>& dir : directions) {
                int nextRow = row + dir[0];
                int nextCol = col + dir[1];

                if (valid(nextRow, nextCol)) {
                    // if the square has already been visited, but with more removals,
                    // then the current path is pointless, since more removals is better
                    if (seen[nextRow][nextCol] >= remain) continue;

                    // check if it is a 1 or 0 cell
                    if (grid[nextRow][nextCol] == 1 && remain > 0) {
                        queue.push({nextRow, nextCol, remain - 1, steps + 1});
                        seen[nextRow][nextCol] = remain;
                    } else if (grid[nextRow][nextCol] == 0) {
                        queue.push({nextRow, nextCol, remain, steps + 1});
                        seen[nextRow][nextCol] = remain;
                    }
                }
            }
        }

        return -1;
    }

    bool valid(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
};
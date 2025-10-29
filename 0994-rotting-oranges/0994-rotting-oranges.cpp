class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // enqueue all rotten oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    ++fresh;
            }
        }

        if (fresh == 0) return 0;

        int minutes = 0;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // BFS level by level
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int k = 0; k < size; ++k) {
                auto [r, c] = q.front(); q.pop();

                for (auto [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;    // mark as rotten
                        q.push({nr, nc});
                        rotted = true;
                        --fresh;
                    }
                }
            }

            if (rotted) ++minutes;
        }

        return fresh == 0 ? minutes : -1;
    }
};

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        // convert grid to 1D array
        vector<int> cells(n * n + 1, -1);
        int idx = 1;
        bool leftToRight = true;

        for (int row = n - 1; row >= 0; row--) {
            if (leftToRight) {
                for (int col = 0; col < n; col++) {
                    cells[idx++] = board[row][col];
                }
            } else {
                for (int col = n - 1; col >= 0; col--) {
                    cells[idx++] = board[row][col];
                }
            }

            leftToRight = !leftToRight;
        }

        // BFS
        queue<vector<int>> queue;   // cell, steps
        vector<bool> seen(n * n + 1, false);

        queue.push({1, 0});
        seen[1] = true;

        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();

            int cell = curr[0], steps = curr[1];

            // check if we have reached the destination
            if (cell == n * n) return steps;

            for (int next = cell + 1; next <= min(cell + 6, n * n); next++) {
                int dst = (cells[next] != -1) ? cells[next] : next;

                if (!seen[dst]) {
                    seen[dst] = true;
                    queue.push({dst, steps + 1});
                }
            }
        }

        return -1;
    }
};
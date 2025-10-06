class Solution {
public:
    int m;
    int n;
    vector<vector<char>> grid;
    vector<vector<bool>> seen;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        this->grid = maze;
        m = maze.size();
        n = maze[0].size();

        seen = vector(m, vector<bool>(n, false));
        seen[entrance[0]][entrance[1]] = true;    // mark the entrance as visited

        queue<vector<int>> queue;
        queue.push({entrance[0], entrance[1], 0});

        // problem: start a BFS from the entrance and find closest border
        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();

            int row = curr[0], col = curr[1], steps = curr[2];

            for (vector<int>& dir : directions) {
                int nextRow = row + dir[0];
                int nextCol = col + dir[1];

                if (border(nextRow, nextCol) && seen[nextRow][nextCol] == false) return steps + 1;

                if (valid(nextRow, nextCol) && seen[nextRow][nextCol] == false) {
                    seen[nextRow][nextCol] = true;
                    queue.push({nextRow, nextCol, steps + 1});
                }
            }
        }

        return -1;
    }

    bool valid(int row, int col) {
        return row > 0 && row < m - 1 && col > 0 && col < n - 1 && grid[row][col] == '.';
    }

    bool border(int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n) return false;

        return (row == 0 || row == m - 1 || col == 0 || col == n - 1) 
            && grid[row][col] == '.';
    }
};
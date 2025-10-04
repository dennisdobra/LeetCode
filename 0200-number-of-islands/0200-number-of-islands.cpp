class Solution {
public:
    int m;
    int n;
    vector<vector<char>> grid;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> seen;

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        this->grid = grid;

        // create a grid with the same dimensions as input where each cell is marked as not visited
        seen = vector(m, vector<bool>(n, false));

        int num_islands = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1' && seen[row][col] == false) {
                    // this piece of land has not been visited yet
                    num_islands++;
                    seen[row][col] = true;  // mark as visited
                    dfs(row, col);          // start dfs from here
                }
            }
        }

        return num_islands;
    }

    /* RECURSIVE DFS */
    void dfs(int row, int col) {
        // start dfs from every valid neighbor
        for (vector<int>& dir : directions) {
            int nextRow = row + dir[0];
            int nextCol = col + dir[1];

            // check if the next cell is valid
            if (valid(nextRow, nextCol) && seen[nextRow][nextCol] == false) {
                seen[nextRow][nextCol] = true;  // mark as visited
                dfs(nextRow, nextCol);
            }
        }
    }

    /* ITERATIVE DFS */
    void iterative_dfs(int startRow, int startCol) {
        stack<pair<int, int>> stack;
        stack.push(pair(startRow, startCol));

        while (!stack.empty()) {
            auto[row, col] = stack.top();
            stack.pop();

            for (vector<int>& dir : directions) {
                int nextRow = row + dir[0];
                int nextCol = col + dir[1];

                if (valid(nextRow, nextCol) && seen[nextRow][nextCol] == false) {
                    seen[nextRow][nextCol] = true;
                    stack.push(pair(nextRow, nextCol));
                }
            }
        }
    }

    bool valid(int row, int col) {
        return 0 <= row && row < m && 0 <= col && col < n && grid[row][col] == '1';
    }
};
class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> grid;
    vector<vector<int>> times;
    int m;
    int n;

    int orangesRotting(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();

        times = vector(m, vector<int>(n, INT_MAX));

        // start a BFS from every rotten orange
        // queue storing (row, col, minutes)

        queue<vector<int>> queue;

        int freshOranges = 0;
        int rottenOranges = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    // found a rotten orange
                    queue.push({i, j, 0});
                    times[i][j] = 0;
                    rottenOranges++;
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        if (freshOranges == 0 && rottenOranges == 0) return 0;

        cout << "fresh: " << freshOranges << endl;
        cout << "rotten: " << rottenOranges << endl;

        if (rottenOranges == 0) return -1;

        int maxMinutes = 0;
        while (!queue.empty()) {
            vector<int> tmp = queue.front();
            queue.pop();

            int currRow = tmp[0], currCol = tmp[1], currMinutes = tmp[2];

            for (vector<int> dir : directions) {
                int newRow = currRow + dir[0];
                int newCol = currCol + dir[1];

                if (isValid(newRow, newCol) && grid[newRow][newCol] != 0 &&
                    currMinutes + 1 < times[newRow][newCol]) {
                        // check if it is a fresh orange
                        if (grid[newRow][newCol] == 1) freshOranges--;

                        times[newRow][newCol] = currMinutes + 1;
                        queue.push({newRow, newCol, currMinutes + 1});
                }
            }
        }

        if (freshOranges != 0) return -1;


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (times[i][j] != INT_MAX && times[i][j] > maxMinutes) {
                    maxMinutes = times[i][j];
                }
            }
        }

        return maxMinutes;
    }

    bool isValid(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
};


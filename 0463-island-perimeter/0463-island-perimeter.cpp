class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m;  // nr rows
    int n;  // nr cols
    vector<vector<int>> grid;
    vector<vector<bool>> seen;

    int islandPerimeter(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();

        int perimeter = 0;

        int row = -1, col = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    row = i;
                    col = j;
                    break;
                }
            }

            if (row != -1) break;
        }

        // start a BFS from node [row][col]

        queue<pair<int, int>> queue;
        queue.push({row, col});

        seen = vector(m, vector<bool>(n, false));
        seen[row][col] = true;

        while (!queue.empty()) {
            auto [currRow, currCol] = queue.front();
            queue.pop();

            perimeter += isConnectedToWater(currRow, currCol);

            // push the valid neighbours into the queue
            for (vector<int> dir : directions) {
                int newRow = currRow + dir[0];
                int newCol = currCol + dir[1];

                if (isValid(newRow, newCol) && grid[newRow][newCol] == 1 && seen[newRow][newCol] == false) {
                    queue.push({newRow, newCol});
                    seen[newRow][newCol] = true;
                }
            }
        }

        return perimeter;
    }

    bool isValid(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }


    int isConnectedToWater(int row, int col) {
        int count = 0;
        for (vector<int> dir : directions) {
            if (isValid(row + dir[0], col + dir[1]) && grid[row + dir[0]][col + dir[1]] == 0) {
                // water cell
                count++;
            } else if (!isValid(row + dir[0], col + dir[1])) {
                // border cell
                count++;
            }
        }
            
        return count;
    }
};
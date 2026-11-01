class Solution {
    int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    boolean[][] seen;
    int m;
    int n;

    public int numIslands(char[][] grid) {
        m = grid.length;
        n = grid[0].length;
        seen = new boolean[m][n];

        int ans = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1' && seen[row][col] == false) {
                    seen[row][col] = true;
                    dfs(row, col, grid);
                    ans++;
                }
            }
        }

        return ans;
    }

    public void dfs(int row, int col, char[][] grid) {
        for (int[] dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (isValid(newRow, newCol, grid) && seen[newRow][newCol] == false) {
                seen[newRow][newCol] = true;
                dfs(newRow, newCol, grid);
            }
        }
    }

    public boolean isValid(int row, int col, char[][] grid) {
        return row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == '1';
    }
}
class State {
    int row;
    int col;
    int steps;

    public State(int row, int col, int steps) {
        this.row = row;
        this.col = col;
        this.steps = steps;
    }
}

class Solution {
    int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m;
    int n;

    public int[][] updateMatrix(int[][] mat) {
        m = mat.length;
        n = mat[0].length;

        Queue<State> queue = new ArrayDeque<>();
        boolean[][] seen = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    queue.offer(new State(i, j, 1));
                    seen[i][j] = true;
                }
            }
        }

        while (!queue.isEmpty()) {
            State curr = queue.poll();
            int row = curr.row;
            int col = curr.col;
            int steps = curr.steps;

            for (int[] dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (isValid(newRow, newCol, mat) && seen[newRow][newCol] == false) {
                    seen[newRow][newCol] = true;
                    mat[newRow][newCol] = steps;

                    queue.offer(new State(newRow, newCol, steps + 1));
                }
            }
        }

        return mat;
    }

    public boolean isValid(int row, int col, int[][] mat) {
        return row >= 0 && row < m && col >= 0 && col < n && mat[row][col] == 1;
    }
}
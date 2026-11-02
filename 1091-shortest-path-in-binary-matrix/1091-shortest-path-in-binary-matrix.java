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
    int[][] directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int n;

    public int shortestPathBinaryMatrix(int[][] grid) {
        if (grid[0][0] != 0) return -1;

        n = grid.length;

        Queue<State> queue = new ArrayDeque<>();
        queue.offer(new State(0, 0, 1));
        grid[0][0] = 1; // mark as visited

        while (!queue.isEmpty()) {
            State curr = queue.poll();
            int row = curr.row;
            int col = curr.col;
            int steps = curr.steps;

            if (row == n - 1 && col == n - 1) return steps;

            for (int[] dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (isValid(newRow, newCol, grid)) {
                    grid[newRow][newCol] = 1;
                    queue.offer(new State(newRow, newCol, steps + 1));
                }
            }
        }

        return -1;
    }

    public boolean isValid(int row, int col, int[][] grid) {
        return row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0;
    }
}
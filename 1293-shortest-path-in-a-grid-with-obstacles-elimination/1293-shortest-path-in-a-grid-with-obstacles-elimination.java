class State {
    int row;
    int col;
    int steps;
    int obstacles;

    public State(int row, int col, int steps, int obstacles) {
        this.row = row;
        this.col = col;
        this.steps = steps;
        this.obstacles = obstacles;
    }
}

class Solution {
    int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m;
    int n;

    public int shortestPath(int[][] grid, int k) {
        m = grid.length;
        n = grid[0].length;

        Queue<State> queue = new ArrayDeque<>();
        int[][] seen = new int[m][n];
        for (int[] row : seen) {
            Arrays.fill(row, -1);
        }

        queue.offer(new State(0, 0, 0, k));
        seen[0][0] = k;

        while (!queue.isEmpty()) {
            State curr = queue.poll();
            int row = curr.row;
            int col = curr.col;
            int steps = curr.steps;
            int obstacles = curr.obstacles;

            if (row == m - 1 && col == n - 1) {
                return steps;
            }

            for (int[] dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (!isValid(newRow, newCol)) continue;

                // if the current square has already been visited with 
                // more removals then the current path is pointless
                if (seen[newRow][newCol] < obstacles) {
                    if (grid[newRow][newCol] == 1 && obstacles > 0) {
                        seen[newRow][newCol] = obstacles - 1;
                        queue.offer(new State(newRow, newCol, steps + 1, obstacles - 1));
                    } else if (grid[newRow][newCol] == 0) {
                        seen[newRow][newCol] = obstacles;
                        queue.offer(new State(newRow, newCol, steps + 1, obstacles));
                    }
                }
            }
        }

        return -1;
    }

    boolean isValid(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
}
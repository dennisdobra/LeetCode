class Solution {
    public int equalPairs(int[][] grid) {
        Map<String, Integer> rows = new HashMap<>();
        Map<String, Integer> cols = new HashMap<>();

        StringBuilder sb = new StringBuilder();
        for (int[] row : grid) {
            for (int num : row) {
                sb.append(num);
                sb.append(',');
            }
            sb.deleteCharAt(sb.length() - 1);

            String key = sb.toString();
            sb.setLength(0);

            rows.put(key, rows.getOrDefault(key, 0) + 1);
        }

        // pe coloane nu exista un for-each echivalent deoarece matricea este stocata ca array de linii
        for (int i = 0; i < grid[0].length; i++) {
            for (int j = 0; j < grid.length; j++) {
                sb.append(grid[j][i]);
                sb.append(',');
            }
            sb.deleteCharAt(sb.length() - 1);

            String key = sb.toString();
            sb.setLength(0);

            cols.put(key, cols.getOrDefault(key, 0) + 1);
        }

        int ans = 0;
        for (var entry : rows.entrySet()) {
            if (cols.containsKey(entry.getKey())) {
                ans += entry.getValue() * cols.get(entry.getKey());
            }
        }

        return ans;
    }
}
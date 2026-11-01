class Solution {
    Map<Integer, List<Integer>> graph;
    Set<Integer> seen;

    public int findCircleNum(int[][] isConnected) {
        graph = new HashMap<>();
        seen = new HashSet<>();

        int n = isConnected.length;

        // create the graph
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    graph.computeIfAbsent(i, k -> new ArrayList<>()).add(j);
                    graph.computeIfAbsent(j, k -> new ArrayList<>()).add(i);
                }   
            }
        }

        int provinces = 0;

        // start a dfs from every unvisited node
        for (int i = 0; i < n; i++) {
            if (!seen.contains(i)) {
                seen.add(i);
                dfs(i);
                provinces++;
            }
        }

        return provinces;
    }

    public void dfs(int node) {
        for (int neigh : graph.getOrDefault(node, new ArrayList<>())) {
            if (!seen.contains(neigh)) {
                seen.add(neigh);
                dfs(neigh);
            }
        }
    }
}
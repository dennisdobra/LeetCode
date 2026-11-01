class Solution {
    Map<Integer, List<Integer>> graph = new HashMap<>();
    Set<String> roads = new HashSet<>();
    Set<Integer> seen = new HashSet<>();

    public int minReorder(int n, int[][] connections) {
        for (int i = 0; i < n; i++) {
            graph.put(i, new ArrayList<>());
        }

        // build the undirected graph
        for (int[] edge : connections) {
            int from = edge[0];
            int to = edge[1];

            graph.get(from).add(to);
            graph.get(to).add(from);

            roads.add(convertToHash(from, to));
        }

        // start a dfs from node 0
        seen.add(0);
        return dfs(0);
    }

    public int dfs(int node) {
        int ans = 0;

        for (int neigh : graph.get(node)) {
            if (!seen.contains(neigh)) {
                seen.add(neigh);

                if (roads.contains(convertToHash(node, neigh))) {
                    ans++;
                }

                ans += dfs(neigh);
            }
        }

        return ans;
    }

    String convertToHash(int from, int to) {
        return from + "->" + to;
    }
}
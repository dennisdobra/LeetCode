class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        Map<Integer, Integer> indegree = new HashMap<>();
        for (List<Integer> edge : edges) {
            int dst = edge.get(1);

            indegree.put(dst, indegree.getOrDefault(dst, 0) + 1);
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!indegree.containsKey(i)) {
                ans.add(i);
            }
        }

        return ans;
    }
}
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Pair {
    int node;
    int steps;

    public Pair(int node, int steps) {
        this.node = node;
        this.steps = steps;
    }
}

class Solution {
    Map<Integer, List<Integer>> graph = new HashMap<>();

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        dfs(root);

        // start a bfs from node target
        Queue<Pair> queue = new ArrayDeque<>();
        queue.offer(new Pair(target.val, 0));

        Set<Integer> seen = new HashSet<>();
        seen.add(target.val);

        List<Integer> ans = new ArrayList<>();

        while (!queue.isEmpty()) {
            Pair pair = queue.poll();
            int node = pair.node;
            int steps = pair.steps;

            if (steps == k) {
                ans.add(node);
                continue;
            }

            for (int neigh : graph.get(node)) {
                if (!seen.contains(neigh)) {
                    seen.add(neigh);
                    queue.offer(new Pair(neigh, steps + 1));
                }
            }
        }

        return ans;
    }

    // traverse the tree and create the undirected graph
    public void dfs(TreeNode node) {
        if (node == null) return;

        if (!graph.containsKey(node.val)) {
            graph.put(node.val, new ArrayList<>());
        }

        if (node.left != null) {
            graph.get(node.val).add(node.left.val);
            if (!graph.containsKey(node.left.val)) {
                graph.put(node.left.val, new ArrayList<>());
            }
            graph.get(node.left.val).add(node.val);
        }

        if (node.right != null) {
            graph.get(node.val).add(node.right.val);
            if (!graph.containsKey(node.right.val)) {
                graph.put(node.right.val, new ArrayList<>());
            }
            graph.get(node.right.val).add(node.val);
        }

        dfs(node.left);
        dfs(node.right);
    }
}
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    Map<TreeNode, TreeNode> parents = new HashMap<>();
        
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        dfs(root, null);

        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(target);

        Set<TreeNode> seen = new HashSet<>();
        seen.add(target);

        int distance = 0;
        while (!queue.isEmpty() && distance < k) {
            int currLength = queue.size();

            for (int i = 0; i < currLength; i++) {
                TreeNode node = queue.poll();

                for (TreeNode neigh : new TreeNode[]{node.left, node.right, parents.get(node)}) {
                    if (neigh != null && !seen.contains(neigh)) {
                        seen.add(neigh);
                        queue.offer(neigh);
                    }
                }
            }

            distance++;
        }

        List<Integer> ans = new ArrayList<>();
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            ans.add(node.val);
        }

        return ans;
    }

    public void dfs(TreeNode node, TreeNode parent) {
        if (node == null) return;

        parents.put(node, parent);

        dfs(node.left, node);
        dfs(node.right, node);
    }
}
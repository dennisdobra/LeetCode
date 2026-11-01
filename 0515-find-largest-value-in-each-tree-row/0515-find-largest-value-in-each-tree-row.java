/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> largestValues(TreeNode root) {
        if (root == null) return new ArrayList<>();

        List<Integer> ans = new ArrayList<>();

        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int nodesInCurrLevel = queue.size();
            int maxOnLevel = Integer.MIN_VALUE;

            for (int i = 0; i < nodesInCurrLevel; i++) {
                TreeNode curr = queue.poll();

                maxOnLevel = Math.max(maxOnLevel, curr.val);

                if (curr.left != null) queue.offer(curr.left);
                if (curr.right != null) queue.offer(curr.right);
            }

            ans.add(maxOnLevel);
        }

        return ans;
    }
}
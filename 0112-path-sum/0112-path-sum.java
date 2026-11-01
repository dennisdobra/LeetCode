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
    int target;

    public boolean dfs(TreeNode node, int curr) {
        if (node == null) {
            return false;
        }

        if (node.left == null && node.right == null) {
            return node.val + curr == target;
        }

        boolean left = dfs(node.left, curr + node.val);
        boolean right = dfs(node.right, curr + node.val);

        return left || right;
    }

    // RECURSIVE WITH HELPER FUNCTION
    public boolean hasPathSum(TreeNode root, int targetSum) {
        target = targetSum;
        return dfs(root, 0);
    }
}
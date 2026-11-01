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
    int good = 0;

    void dfs(TreeNode node, int largestSoFar) {
        if (node == null) return;

        if (node.val >= largestSoFar) {
            good++;
        }

        dfs(node.left, Math.max(node.val, largestSoFar));
        dfs(node.right, Math.max(node.val, largestSoFar));
    }

    public int goodNodes(TreeNode root) {
        // start a dfs traversal from the root. At each node I also need
        // to have the largest seen so far starting from the root =>
        // I need a helper function
        dfs(root, root.val);
        return good;
    }
}
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

    void dfs_(TreeNode node, int largestSoFar) {
        if (node == null) return;

        if (node.val >= largestSoFar) {
            good++;
        }

        dfs(node.left, Math.max(node.val, largestSoFar));
        dfs(node.right, Math.max(node.val, largestSoFar));
    }

    /* RECURSIVE + HELPER FUNCTION */
    public int goodNodes_(TreeNode root) {
        // start a dfs traversal from the root. At each node I also need
        // to have the largest seen so far starting from the root =>
        // I need a helper function
        dfs(root, root.val);
        return good;
    }

    int dfs(TreeNode node, int largestSoFar) {
        if (node == null) return 0;

        largestSoFar = Math.max(largestSoFar, node.val);

        int left = dfs(node.left, largestSoFar);
        int right = dfs(node.right, largestSoFar);

        int ans = left + right;

        // check if the current node is good
        if (node.val >= largestSoFar) {
            ans++;
        }

        return ans;
    }

    /* RECURSIVE + HELPER FUNCTION 2 */
    public int goodNodes(TreeNode root) {
        return dfs(root, Integer.MIN_VALUE);
    }
}
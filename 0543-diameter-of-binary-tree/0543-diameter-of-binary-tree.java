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
    int maxDepth(TreeNode node) {
        if (node == null) return 0;

        int left = maxDepth(node.left);
        int right = maxDepth(node.right);

        return 1 + Math.max(left, right);
    }

    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) return 0;

        int left = maxDepth(root.left);
        int right = maxDepth(root.right);

        int diameter = left + right;

        return Math.max(
            diameter,
            Math.max(diameterOfBinaryTree(root.left), diameterOfBinaryTree(root.right))
        );
    }
}
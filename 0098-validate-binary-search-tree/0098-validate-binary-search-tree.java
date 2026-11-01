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
    public boolean checkBST(TreeNode node, long small, long large) {
        if (node == null) return true;

        // the value of the current node must be in range (small, large)
        if (node.val <= small || node.val >= large) return false;

        // update small and large values based on which subtree is explored
        boolean left = checkBST(node.left, small, node.val);
        boolean right = checkBST(node.right, node.val, large);

        return left && right;
    }

    public boolean isValidBST(TreeNode root) {
        // the root can have any value since it does not have parents
        return checkBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}
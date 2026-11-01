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
    public int minDepth(TreeNode root) {
        if (root == null) return 0;

        // the current node is a leaf
        if (root.left == null && root.right == null) return 1;

        // if one child is null, only check the other subtree
        if (root.left == null) return 1 + minDepth(root.right);
        else if (root.right == null) return 1 + minDepth(root.left);

        // if both children are not null, check both subtrees
        return 1 + Math.min(minDepth(root.left), minDepth(root.right));
    }
}
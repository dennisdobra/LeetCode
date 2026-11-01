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
    // public int sumOfAllNodes(TreeNode root) {
    //     if (root == null) return 0;

    //     return root.val + sumOfAllNodes(root.left) + sumOfAllNodes(root.right);
    // }

    public int rangeSumBST(TreeNode root, int low, int high) {
        if (root == null) return 0;

        // to add to the sum the current node must be between low and high
        if (root.val >= low && root.val <= high) {
            return root.val + rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high);
        }

        // the current node is not in between low and high
        // it is either larger than high or lower than low
        if (root.val > high) {
            // it is not worth looking in the right subtree of the current node
            return rangeSumBST(root.left, low, high);
        }

        return rangeSumBST(root.right, low, high);
    }
}
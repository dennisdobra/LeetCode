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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // base case: empty tree => no LCA exists
        if (root == null) return null;

        // if the current node is p or q => the answer can't be below the current node
        if (root == p || root == q) return root;

        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        // one of them is in the left subtree and the other is in the right subtree
        // => root is the lowest having them both in its subtree
        if (left != null && right != null) return root;

        // both p and q are in one of the subtrees
        if (left != null && right == null) return left;
        
        return right;
    }
}
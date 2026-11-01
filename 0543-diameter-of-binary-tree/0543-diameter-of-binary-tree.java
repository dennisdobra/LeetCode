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
// class Solution {
//     // helper function to compute max depth from a node to a leaf
//     public int maxDepth(TreeNode node) {
//         if (node == null) return 0;
        
//         int left = maxDepth(node.left);
//         int right = maxDepth(node.right);
        
//         return 1 + Math.max(left, right);
//     }
    
//     // Time Complexity: O(N^2) because we call maxDepth (which is O(N)) for every node in the tree
//     // Space Complexity: O(h), where h is the height of the tree (best case: logN, worst case: N)
//     public int diameterOfBinaryTree(TreeNode root) {
//         if (root == null) return 0;
        
//         int left = maxDepth(root.left);
//         int right = maxDepth(root.right);
        
//         // OBS: the diameter is measured in the number of edges, not in the number of nodes
//         //      so in this case there is no need to add + 1 (left + right + 1)
//         int diameter = left + right;
        
//         return Math.max(
//             diameter,
//             Math.max(diameterOfBinaryTree(root.left), diameterOfBinaryTree(root.right))
//         );
//     }
// }

class Solution {
    private int diameter;

    private int maxDepth(TreeNode node) {
        if (node == null) return 0;

        int left = maxDepth(node.left);
        int right = maxDepth(node.right);

        diameter = Math.max(diameter, left + right);

        return 1 + Math.max(left, right);
    }

    public int diameterOfBinaryTree(TreeNode root) {
        diameter = 0;

        // call the maxDepth function to compute the value for diameter
        maxDepth(root);

        return diameter;
    }
}
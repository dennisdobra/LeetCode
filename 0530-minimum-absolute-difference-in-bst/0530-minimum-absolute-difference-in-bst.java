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
    // public int getMinimumDifference_(TreeNode root) {
    //     List<Integer> sorted = new ArrayList<>();

    //     dfs(root, sorted);

    //     int minDiff = Integer.MAX_VALUE;
    //     for (int i = 0; i < sorted.size() - 1; i++) {
    //         minDiff = Math.min(minDiff, sorted.get(i + 1) - sorted.get(i));
    //     }

    //     return minDiff;
    // }

    // public void dfs(TreeNode node, List<Integer> values) {
    //     if (node == null) return;

    //     // inorder dfs
    //     dfs(node.left, values);
    //     values.add(node.val);
    //     dfs(node.right, values);
    // }


    int minDiff = Integer.MAX_VALUE;
    TreeNode prev = null;

    public void dfs(TreeNode node) {
        if (node == null) return;

        dfs(node.left);

        if (prev != null) {
            minDiff = Math.min(minDiff, Math.abs(node.val - prev.val));
        }
        prev = node;

        dfs(node.right);
    }

    public int getMinimumDifference(TreeNode root) {
        dfs(root);
        return minDiff;
    }
}
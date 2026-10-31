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

class Pair {
    TreeNode node;
    int depth;

    public Pair(TreeNode node, int depth) {
        this.node = node;
        this.depth = depth;
    }
}

class Solution {
    // RECURSIVE SOLUTION: O(N) Time and O(N) Space
    public int maxDepth_(TreeNode root) {
        if (root == null) return 0;

        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }

    // ITERATIVE SOLUTION:
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;

        Deque<Pair> stack = new ArrayDeque<>();
        stack.push(new Pair(root, 1));

        int ans = 0;
        while (!stack.isEmpty()) {
            Pair pair = stack.pop();
            TreeNode node = pair.node;
            int depth = pair.depth;

            ans = Math.max(ans, depth);

            if (node.left != null) {
                stack.push(new Pair(node.left, depth + 1));
            }

            if (node.right != null) {
                stack.push(new Pair(node.right, depth + 1));
            }
        }

        return ans;
    }
}
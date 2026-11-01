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
    int sum;

    Pair(TreeNode node, int sum) {
        this.node = node;
        this.sum = sum;
    }
}

class Solution {
    int target;

    public boolean dfs(TreeNode node, int curr) {
        if (node == null) {
            return false;
        }

        if (node.left == null && node.right == null) {
            return node.val + curr == target;
        }

        boolean left = dfs(node.left, curr + node.val);
        boolean right = dfs(node.right, curr + node.val);

        return left || right;
    }

    // RECURSIVE WITH HELPER FUNCTION
    public boolean hasPathSum_(TreeNode root, int targetSum) {
        target = targetSum;
        return dfs(root, 0);
    }

    // RECURSIVE WITHOUT HELPER FUNCTION
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) return false;

        if (root.left == null && root.right == null) {
            return root.val == targetSum;
        }

        boolean left = hasPathSum(root.left, targetSum - root.val);
        boolean right = hasPathSum(root.right, targetSum - root.val);

        return left || right;
    }

    // ITERATIVE
    public boolean hasPathSum__(TreeNode root, int targetSum) {
        if (root == null) return false;

        Deque<Pair> stack = new ArrayDeque<>();
        stack.push(new Pair(root, root.val));

        while (!stack.isEmpty()) {
            Pair curr = stack.pop();
            TreeNode node = curr.node;
            int sum = curr.sum;

            if (node.left == null && node.right == null) {
                if (sum == targetSum) {
                    return true;
                }
            }

            if (node.left != null) {
                stack.push(new Pair(node.left, sum + node.left.val));
            }

            if (node.right != null) {
                stack.push(new Pair(node.right, sum + node.right.val));
            }
        }

        return false;
    }
}
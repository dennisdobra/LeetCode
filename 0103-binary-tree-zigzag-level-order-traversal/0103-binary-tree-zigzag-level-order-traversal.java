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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
       if (root == null) return new ArrayList<>();
       
        List<List<Integer>> ans = new ArrayList<>();

        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);

        int levelIdx = 0;
        while (!queue.isEmpty()) {
            int nodesInCurrLevel = queue.size();
            List<Integer> level = new ArrayList<>();

            for (int i = 0; i < nodesInCurrLevel; i++) {
                TreeNode curr = queue.poll();
                level.add(curr.val);

                if (curr.left != null) queue.offer(curr.left);
                if (curr.right != null) queue.offer(curr.right);
            }

            if (levelIdx % 2 != 0) {
                Collections.reverse(level);
            }

            ans.add(level);
            levelIdx++;
        }

        return ans;
    }
}
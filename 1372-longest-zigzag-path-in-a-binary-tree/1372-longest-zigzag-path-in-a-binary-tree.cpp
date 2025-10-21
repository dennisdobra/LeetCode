/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLength = 0;

    void dfs(TreeNode* node, bool goLeft, int steps) {
        if (node == nullptr) return;

        maxLength = max(steps, maxLength);

        // see in which way we can continue the zig-zag path
        // and in which way we have to start over
        if (goLeft == true) {
            dfs(node->left, false, steps + 1);  // false because at the next call we won't be able to go left
            dfs(node->right, true, 1);          // begin a new zigzag path of length 1
        } else {
            dfs(node->left, false, 1);
            dfs(node->right, true, steps + 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        return maxLength;
    }
};
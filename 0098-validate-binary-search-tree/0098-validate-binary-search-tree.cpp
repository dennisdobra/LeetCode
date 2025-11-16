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
    bool isValidBST(TreeNode* root) {
        long small = LONG_MIN;
        long large = LONG_MAX;

        return dfs(root, small, large);
    }

    bool dfs(TreeNode* node, long small, long large) {
        if (node == nullptr) return true;

        // check constraint for current node
        if (node->val <= small || node->val >= large) return false;

        bool left = dfs(node->left, small, node->val);
        bool right = dfs(node->right, node->val, large);

        return left && right;
    }
};
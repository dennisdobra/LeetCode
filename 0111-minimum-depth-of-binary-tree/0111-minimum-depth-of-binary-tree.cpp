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
    int minDepth(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // only one children is non-null
        if (root->left == nullptr) {
            return 1 + dfs(root->right);
        } else if (root->right == nullptr) {
            return 1 + dfs(root->left);
        }

        // both children are non-null
        return 1 + min(dfs(root->left), dfs(root->right));
    }
};
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
    TreeNode* dfs(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;

        if (root->val == val) return root;

        if (val < root->val) return dfs(root->left, val);   // return left subtree to search for val
        return dfs(root->right, val);                       // return right subtree to search for val
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return dfs(root, val);
    }
};
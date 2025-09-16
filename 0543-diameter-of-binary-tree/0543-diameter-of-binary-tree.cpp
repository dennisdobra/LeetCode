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
private:
    int diameter;

    int maxDepth(TreeNode* node) {
        if (node == nullptr) return 0;

        int left = maxDepth(node->left);
        int right = maxDepth(node->right);
        return 1 + max(left, right);
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) return;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        diameter = max(diameter, leftDepth + rightDepth);

        dfs(root->left);
        dfs(root->right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        dfs(root);
        return diameter;
    }    
};
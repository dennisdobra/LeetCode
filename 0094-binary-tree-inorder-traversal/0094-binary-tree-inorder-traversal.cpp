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
    vector<int>ans;

    void inorderDFS(TreeNode* node) {
        if (node == nullptr) return;

        inorderDFS(node->left);
        ans.push_back(node->val);
        inorderDFS(node->right);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorderDFS(root);
        return ans;
    }
};
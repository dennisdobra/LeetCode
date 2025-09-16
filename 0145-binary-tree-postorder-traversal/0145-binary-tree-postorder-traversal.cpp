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
    vector<int> ans;

    void postorderDFS(TreeNode* node) {
        if (node == nullptr) return;

        postorderDFS(node->left);
        postorderDFS(node->right);
        ans.push_back(node->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        postorderDFS(root);
        return ans;
    }
};
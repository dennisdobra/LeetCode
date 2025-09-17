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
    vector<int> lonely;

    void dfs(TreeNode* node) {
        if (node == nullptr) return;

        if (node->left == nullptr && node->right != nullptr) {
            lonely.push_back(node->right->val);
        }

        if (node->left != nullptr && node->right == nullptr) {
            lonely.push_back(node->left->val);
        }

        dfs(node->left);
        dfs(node->right);
    }
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        dfs(root);
        return lonely;
    }

    
};
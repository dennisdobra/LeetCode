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
    vector<int> leaves1;
    vector<int> leaves2;

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, leaves1);
        dfs(root2, leaves2);

        if (leaves1.size() != leaves2.size()) return false;

        for (int i = 0; i < leaves1.size(); i++) {
            if (leaves1[i] != leaves2[i]) return false;
        }

        return true;
    }

    void dfs(TreeNode* root, vector<int>& leaves) {
        if (root == nullptr) return;

        // check if we have reached a leaf
        if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(root->val);
        }

        dfs(root->left, leaves);
        dfs(root->right, leaves);
    }
};
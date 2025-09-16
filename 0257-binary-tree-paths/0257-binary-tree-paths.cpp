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
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(TreeNode* node) {
        if (node == nullptr) return;

        curr.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr) {
            ans.push_back(curr);
        } else {
            dfs(node->left);
            dfs(node->right);
        }

        curr.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);

        vector<string> result;
        for (vector<int>& v : ans) {
            string path;
            int i;
            for (i = 0; i < v.size() - 1; i++) {
                path += to_string(v[i]);
                path += "->";
            }
            
            path += to_string(v[i]);
            result.push_back(path);
        }

        return result;
    }
};
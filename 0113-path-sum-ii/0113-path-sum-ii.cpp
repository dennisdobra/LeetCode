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
    int target;
    vector<vector<int>> ans;
    vector<int> tmp;

    void dfs(TreeNode* node, int curr) {
        if (node == nullptr) return;

        // add current value to path
        curr += node->val;
        tmp.push_back(node->val);
        
        // if we found a leaf and the sum is correct => save the path
        if (node->left == nullptr && node->right == nullptr) {
            if (curr == target) {
                ans.push_back(tmp);
            }
        } else {
            // continue on subtrees
            dfs(node->left, curr);
            dfs(node->right, curr);
        }

        tmp.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        dfs(root, 0);
        return ans;
    }
};
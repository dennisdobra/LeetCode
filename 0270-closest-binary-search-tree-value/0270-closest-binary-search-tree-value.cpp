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
    int closestValue(TreeNode* root, double target) {
        vector<int> values;
        inorderTraversal(root, values);

        double min_dif = (double)INT_MAX;
        int result;
        for (int i = 0; i < values.size(); i++) {
            if (abs(target - values[i]) < min_dif) {
                min_dif = abs(target - values[i]);
                result = values[i];
            }
        }

        return result;
    }

    void inorderTraversal(TreeNode* root, vector<int>& values) {
        if (root == nullptr) return;

        inorderTraversal(root->left, values);
        values.push_back(root->val);
        inorderTraversal(root->right, values);
    }
};
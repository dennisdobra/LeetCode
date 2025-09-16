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
    int first_min;
    long second_min;

    void dfs(TreeNode* node) {
        if (node == nullptr) return;

        if (node->val > first_min && node->val < second_min) {
            second_min = node->val;
        } else if (node->val == first_min) {
            // there still is a chance to find a second min
            dfs(node->left);
            dfs(node->right);
        }
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        first_min = root->val;
        second_min = LONG_MAX;
        dfs(root);
        return second_min == LONG_MAX ? -1 : second_min;
    }
};
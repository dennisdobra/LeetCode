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
    vector<int> curr;
    vector<vector<int>> numbers;

    void dfs(TreeNode* node) {
        if (node == nullptr) return;

        curr.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr) {
            numbers.push_back(curr);
        } else {
            dfs(node->left);
            dfs(node->right);
        }

        curr.pop_back();
    }

public:
    int sumNumbers(TreeNode* root) {
        dfs(root);

        int totalSum = 0;
        for (vector<int>& v : numbers) {
            int number = 0;
            for (int num : v) {
                number = number * 10 + num;
            }

            totalSum += number;
        }

        return totalSum;
    }
};
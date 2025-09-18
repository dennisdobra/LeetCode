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
    vector<int> values;

    void inorderDFS(TreeNode* node) {
        if (node == nullptr) return;

        inorderDFS(node->left);
        values.push_back(node->val);
        inorderDFS(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        inorderDFS(root);

        int min_dif = INT_MAX;
        for (int i = 0; i < values.size() - 1; i++) {
            if (values[i + 1] - values[i] < min_dif) {
                min_dif = values[i + 1] - values[i];
            }
        }

        return min_dif;
    }
};
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;

        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int nodesInCurrLevel = queue.size();

            double sum = 0;
            for (int i = 0; i < nodesInCurrLevel; i++) {
                TreeNode* node = queue.front();
                queue.pop();

                sum += node->val;

                if (node->left != nullptr) {
                    queue.push(node->left);
                }

                if (node->right != nullptr) {
                    queue.push(node->right);
                } 
            }

            averages.push_back(sum / nodesInCurrLevel);
        }

        return averages;
    }
};
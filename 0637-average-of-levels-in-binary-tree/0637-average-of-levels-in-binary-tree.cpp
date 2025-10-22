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
        queue<TreeNode*> queue;
        queue.push(root);

        double levelAVG;
        vector<double> ans;

        while (!queue.empty()) {
            int nodesInCurrLevel = queue.size();
            
            double sum = 0;
            for (int i = 0; i < nodesInCurrLevel; i++) {
                TreeNode* curr = queue.front();
                queue.pop();

                sum += curr->val;

                if (curr->left != nullptr) queue.push(curr->left);
                if (curr->right != nullptr) queue.push(curr->right);
            }

            levelAVG = sum / nodesInCurrLevel;
            ans.push_back(levelAVG);
        }

        return ans;
    }
};
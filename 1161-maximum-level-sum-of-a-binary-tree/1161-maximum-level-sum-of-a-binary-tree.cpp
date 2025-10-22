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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);

        int maxSum = INT_MIN;
        int ans = 1;
        int level = 0;
        while (!queue.empty()) {
            int nodesInCurrLevel = queue.size();
            level++;

            int currSum = 0;
            for (int i = 0; i < nodesInCurrLevel; i++) {
                TreeNode* curr = queue.front();
                queue.pop();

                currSum += curr->val;

                if (curr->left != nullptr) queue.push(curr->left);
                if (curr->right != nullptr) queue.push(curr->right);
            }

            if (currSum > maxSum) {
                maxSum = currSum;
                ans = level;
            }
        }

        return ans;
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>{};

        queue<TreeNode*> queue;
        queue.push(root);

        vector<vector<int>> ans;

        while (!queue.empty()) {
            int nodesInCurrLevel = queue.size();

            vector<int> tmp;

            for (int i = 0; i < nodesInCurrLevel; i++) {
                TreeNode* curr = queue.front();
                queue.pop();

                tmp.push_back(curr->val);

                if (curr->left != nullptr) queue.push(curr->left);
                if (curr->right != nullptr) queue.push(curr->right);
            }

            ans.push_back(tmp);
        }

        return ans;
    }
};
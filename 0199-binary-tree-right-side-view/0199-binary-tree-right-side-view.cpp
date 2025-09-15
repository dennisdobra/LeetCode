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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int nodesInCurrentLevel = queue.size();

            for (int i = 0; i < nodesInCurrentLevel - 1; i++) {
                TreeNode* node = queue.front();
                queue.pop();

                if (node->left != nullptr) {
                    queue.push(node->left);
                }

                if (node->right != nullptr) {
                    queue.push(node->right);
                }
            }

            TreeNode* last_node = queue.front();
            queue.pop();

            ans.push_back(last_node->val);


            if (last_node->left != nullptr) {
                queue.push(last_node->left);
            }

            if (last_node->right != nullptr) {
                queue.push(last_node->right);
            }
        }

        return ans;
    }
};
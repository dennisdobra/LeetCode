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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>{};

        deque<TreeNode*> deque;
        deque.push_back(root);

        vector<vector<int>> ans;

        bool left = false;
        while (!deque.empty()) {
            int nodesInCurrLevel = deque.size();
            vector<int> curLevel;

            for (int i = 0; i < nodesInCurrLevel; i++) {
                TreeNode* node;
                if (left == true) {
                    node = deque.front();
                    deque.pop_front();
                } else {
                    node = deque.back();
                    deque.pop_back();
                }

                curLevel.push_back(node->val);

                if (left == true) {
                    if (node->right != nullptr) deque.push_back(node->right);
                    if (node->left != nullptr) deque.push_back(node->left);

                    continue;
                }

                if (node->left != nullptr) deque.push_front(node->left);
                if (node->right != nullptr) deque.push_front(node->right);

            }

            left = !left;

            ans.push_back(curLevel);
        }

        return ans;
    }
};
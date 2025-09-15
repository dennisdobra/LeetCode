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

        bool leftToRight = false;
        while (!deque.empty()) {
            int nodesInCurrLevel = deque.size();
            vector<int> currLevelNodes;

            for (int i = 0; i < nodesInCurrLevel; i++) {
                TreeNode* node;

                if (leftToRight == true) {
                    // traverse level from left to right
                    node = deque.front();
                    deque.pop_front();
                } else {
                    // traverse level from right to left
                    node = deque.back();
                    deque.pop_back();
                }

                currLevelNodes.push_back(node->val);
                
                if (leftToRight == true) {
                    if (node->right != nullptr) deque.push_back(node->right);
                    if (node->left != nullptr) deque.push_back(node->left);

                    continue;
                }

                if (node->left != nullptr) deque.push_front(node->left);
                if (node->right != nullptr) deque.push_front(node->right);
            }

            leftToRight = !leftToRight;

            ans.push_back(currLevelNodes);
        }

        return ans;
    }
};
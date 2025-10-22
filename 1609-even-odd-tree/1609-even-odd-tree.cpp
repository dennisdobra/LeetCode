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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);

        int evenLevel = 0;
        while (!queue.empty()) {
            int nodesInCurrLevel = queue.size();

            vector<int> tmp;
            for (int i = 0; i < nodesInCurrLevel; i++) {
                TreeNode* curr = queue.front();
                queue.pop();

                // check if the parity of the value corresponds to the current level
                if (curr->val % 2 == evenLevel) return false;

                if (tmp.size() == 0) {
                    tmp.push_back(curr->val);

                    if (curr->left != nullptr) queue.push(curr->left);
                    if (curr->right != nullptr) queue.push(curr->right);
                    continue;
                }

                // check if the nodes respect the sorting order
                if (evenLevel == 0) {
                    // increasing order
                    if (curr->val <= tmp[tmp.size() - 1]) return false;
                } else {
                    // decreasing order
                    if (curr->val >= tmp[tmp.size() - 1]) return false;
                }

                tmp.push_back(curr->val);
                if (curr->left != nullptr) queue.push(curr->left);
                if (curr->right != nullptr) queue.push(curr->right);
            }

            evenLevel = (evenLevel == 0) ? 1 : 0;
        }

        return true;
    }
};
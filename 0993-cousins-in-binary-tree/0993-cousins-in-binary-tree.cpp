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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int nodesInCurrLevel = queue.size();

            unordered_set<int> seen;
            for (int i = 0; i < nodesInCurrLevel; i++) {
                TreeNode* node = queue.front();
                queue.pop();

                if (node->left != nullptr && node->right != nullptr &&
                    (node->left->val == x && node->right->val == y || node->left->val == y && node->right->val == x)) {
                        return false;
                    }

                seen.insert(node->val);

                if (node->left != nullptr) queue.push(node->left);
                if (node->right != nullptr) queue.push(node->right);
            }

            if (seen.contains(x) && seen.contains(y)) return true;
        }

        return false;
    }
};
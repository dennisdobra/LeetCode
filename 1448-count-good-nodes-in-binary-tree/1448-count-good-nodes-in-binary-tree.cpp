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
    int goodNodes(TreeNode* root) {
        /* RECURSIVE */
        // return dfs(root, INT_MIN);

        /* ITERATIVE */
        if (root == nullptr) return 0;

        stack<pair<TreeNode*, int>> stack;
        stack.push({root, INT_MIN});
        int ans = 0;

        while (!stack.empty()) {
            auto [node, max_so_far] = stack.top();
            stack.pop();

            if (node->val >= max_so_far) {
                ans++;
            }

            if (node->left != nullptr) {
                stack.push({node->left, max(max_so_far, node->val)});
            }

            if (node->right != nullptr) {
                stack.push({node->right, max(max_so_far, node->val)});
            }
        }

        return ans;
    }

    int dfs(TreeNode* node, int max_so_far) {
        if (node == nullptr) {
            return 0;
        }

        // count the number of good nodes in the left subtree
        int left = dfs(node->left, max(max_so_far, node->val));

        // count the number of good nodes in the right subtree
        int right = dfs(node->right, max(max_so_far, node->val));

        int ans = left + right;

        // check if the current node is also a good node
        if (node->val >= max_so_far) {
            ans++;
        }

        return ans;
    }
};
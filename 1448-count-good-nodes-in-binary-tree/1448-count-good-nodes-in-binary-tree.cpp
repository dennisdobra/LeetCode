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
        return dfs(root, INT_MIN);
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
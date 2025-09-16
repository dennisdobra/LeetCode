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
private:
    int ans;

    int solve(TreeNode* node, int parent) {
        if (node == nullptr) return 0;

        // for each left and right child path, find the nr of nodes
        // equal to their parent node
        int left = solve(node->left, node->val);
        int right = solve(node->right, node->val);

        ans = max(ans, left + right);

        if (node->val == parent) {
            return max(left, right) + 1;
        }

        return 0;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        solve(root, -1);

        return ans;
    }
};
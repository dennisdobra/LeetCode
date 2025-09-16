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
    int maxDepth(TreeNode* root) {

        /* RECURSIVELY */
        // if (root == nullptr) return 0;

        // int left = maxDepth(root->left);
        // int right = maxDepth(root->right);
        // return 1 + max(left, right);

        /* ITERATIVELY */
        // if (root == nullptr) {
        //     return 0;
        // }

        // stack<pair<TreeNode*, int>> stack;
        // stack.push({root, 1});
        // int ans = 0;

        // while (!stack.empty()) {
        //     auto [node, depth] = stack.top();
        //     stack.pop();

        //     ans = max(ans, depth);

        //     if (node->left != nullptr) {
        //         stack.push({node->left, depth + 1});
        //     }

        //     if (node->right != nullptr) {
        //         stack.push({node->right, depth + 1});
        //     }
        // }

        // return ans;


        if (root == nullptr) return 0;

        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);

        return 1 + max(left_depth, right_depth);
    }
};
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        // check the condition for the two subtrees for the current node
        if (abs(maxDepth(root->left) - maxDepth(root->right)) >= 2) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }

    // get the height of a subtree
    int maxDepth(TreeNode* node) {
        if (node == nullptr) return 0;

        int left = maxDepth(node->left);
        int right = maxDepth(node->right);

        return 1 + max(left, right);
    }
};
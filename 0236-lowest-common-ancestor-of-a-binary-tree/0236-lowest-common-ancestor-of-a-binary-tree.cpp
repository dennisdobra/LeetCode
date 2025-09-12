/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        // first case -> root is either p or q
        if (root == p || root == q) {
            return root;
        }

        // root is not one of the targets => we need to check subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // second case -> one target is in the left subtree of root and
        //                the second target in the right subtree of root
        //                => LCA is root
        if (left != nullptr && right != nullptr) {
            return root;
        }

        // third case -> one is null (left/right) and the other is not null
        //               => both targets are in the left / right subtree
        if (left != nullptr) {
            return left;
        }

        return right;
    }
};
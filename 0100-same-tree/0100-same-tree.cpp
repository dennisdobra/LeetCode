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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case -> both null => true
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // only one is null => false
        if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        // value of nodes is the same => check if the subtrees are also the same
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        // if both subtrees are the same, we return true 
        return left && right;
    }
};
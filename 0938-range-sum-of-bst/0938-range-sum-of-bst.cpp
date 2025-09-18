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
    int sum;

    void computeSum(TreeNode* node, int low, int high) {
        if (node == nullptr) return;

        if (node->val < low) {
            // ignore left subtree
            computeSum(node->right, low, high);
        } else if (node->val > high) {
            // ignore right subtree
            computeSum(node->left, low, high);
        } else {
            // current node is valid
            sum += node->val;

            computeSum(node->left, low, high);
            computeSum(node->right, low, high);
        }
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        computeSum(root, low, high);
        return sum;
    }
};
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
    void inorderDFS(TreeNode* root, vector<int>& ascending) {
        if (root == nullptr) return;

        inorderDFS(root->left, ascending);
        ascending.push_back(root->val);
        inorderDFS(root->right, ascending);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        vector<int> ans;

        inorderDFS(root1, tree1);
        inorderDFS(root2, tree2);

        // interclasez vectorii tree1 si tree2
        int i = 0, j = 0, k = 0;
        while (i < tree1.size() && j < tree2.size()) {
            if (tree1[i] < tree2[j]) {
                ans.push_back(tree1[i++]);
            } else {
                ans.push_back(tree2[j++]);
            }
        }

        while (i < tree1.size()) {
            ans.push_back(tree1[i++]);
        }

        while (j < tree2.size()) {
            ans.push_back(tree2[j++]);
        }

        return ans;
    }
};
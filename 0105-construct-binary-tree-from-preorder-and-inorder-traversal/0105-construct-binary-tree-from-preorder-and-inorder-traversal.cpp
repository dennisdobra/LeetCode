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
    unordered_map<int, int> inorderMap;

    // initialize an integer variabile preorderIndex to keep track of the
    // the element that will be used to construct the root;
    int preorderIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // build a hashmap to record the relation value->index for inorder,
        // so that we can find the position of  aroot in constant time;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        return arrayToTree(preorder, 0, preorder.size() - 1);
    }

    // this function takes a range of inorder, defined by left and right
    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        // check if the range is empty
        if (left > right) return nullptr;

        // select the preorderIndex element as the root
        int rootValue = preorder[preorderIndex];
        preorderIndex++;

        TreeNode* root = new TreeNode(rootValue);

        // build left and right subtree
        root->left = arrayToTree(preorder, left, inorderMap[rootValue] - 1);       // right is now the index before rootValue in inorder array
        root->right = arrayToTree(preorder, inorderMap[rootValue] + 1, right);     // left is now the index next to the rootValue in inorder array
        
        return root;
    }
};
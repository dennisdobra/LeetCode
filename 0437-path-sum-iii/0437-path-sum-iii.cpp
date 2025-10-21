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
    int target;
    int countPaths = 0;
    unordered_map<long, int> prefixSum;

    void dfs(TreeNode* node, long currSum) {
        if (node == nullptr) return;

        // add the current node to the overall prefix sum
        currSum += node->val;

        // a path starting from root is equal to target
        if (currSum == target) countPaths++;

        // add the number of paths that do not start from root
        countPaths += prefixSum[currSum - target];

        prefixSum[currSum]++;

        dfs(node->left, currSum);
        dfs(node->right, currSum);

        prefixSum[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        dfs(root, 0L);
        return countPaths;
    }
};
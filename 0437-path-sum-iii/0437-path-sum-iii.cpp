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
    int ans = 0;
    unordered_map<long long, int> map;

    void dfs(TreeNode* node, long long currSum) {
        if (node == nullptr) return;

        // current prefix sum
        currSum += node->val;

        if (currSum == target) ans++;

        // the nr of times 'currSum - target' has occured already,
        // determines the nr of times a path with sum target
        // has occured up to the current node
        ans += map[currSum - target];

        // add the current sum into the map
        map[currSum]++;

        dfs(node->left, currSum);
        dfs(node->right, currSum);

        map[currSum] -= 1;
    }

    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        dfs(root, 0LL);
        return ans;
    }
};
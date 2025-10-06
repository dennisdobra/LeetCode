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
    unordered_map<int, vector<int>> graph;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // convert the binary tree in a graph
        dfs(root);

        vector<int> ans;

        queue<int> queue;
        queue.push(target->val);

        unordered_set<int> seen;
        seen.insert(target->val);

        int steps = 0;
        while (!queue.empty() && steps != k) {
            int nodesInCurrLevel = queue.size();

            // put in queue the neighbours of every node in the current level
            for (int i = 0; i < nodesInCurrLevel; i++) {
                int node = queue.front();
                queue.pop();

                for (int neigh : graph[node]) {
                    if (!seen.contains(neigh)) {
                        queue.push(neigh);
                        seen.insert(neigh);
                    }
                }
            }

            steps++;
        }

        while (!queue.empty()) {
            int cur = queue.front();
            queue.pop();
            ans.push_back(cur);
        }

        return ans;
    }

    // helper function to build the bidirectional graph
    void dfs(TreeNode* root) {
        if (root == nullptr) return;

        if (root->left != nullptr) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if (root->right != nullptr) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        dfs(root->left);
        dfs(root->right);
    }
};
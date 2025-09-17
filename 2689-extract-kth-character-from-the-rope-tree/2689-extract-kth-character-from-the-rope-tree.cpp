/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
class Solution {
private:
    string dfs(RopeTreeNode* node) {
        if (node == nullptr) return "";

        if (node->left == nullptr && node->right == nullptr) {
            return node->val;
        }

        string left = dfs(node->left);
        string right = dfs(node->right);

        string result = left;
        result += right;
        return result;
    }
public:
    char getKthCharacter(RopeTreeNode* root, int k) {
        string str = dfs(root);
        return str[k - 1];
    }
};
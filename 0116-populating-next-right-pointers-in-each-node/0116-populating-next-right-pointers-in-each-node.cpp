/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        queue<Node*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int NodesInCurrLevel = queue.size();

            vector<Node*> currNodes;
            for (int i = 0; i < NodesInCurrLevel; i++) {
                Node* curr = queue.front();
                queue.pop();

                currNodes.push_back(curr);
            }

            // set next pointer
            for (int i = 0; i < currNodes.size() - 1; i++) {
                currNodes[i]->next = currNodes[i + 1];

                // add the children to the queue
            }
            currNodes[currNodes.size() - 1]->next = nullptr;

            for (int i = 0; i < currNodes.size(); i++) {
                if (currNodes[i]->left != nullptr) {
                    queue.push(currNodes[i]->left);
                }
                if (currNodes[i]->right != nullptr) {
                    queue.push(currNodes[i]->right);
                }
            }
        }

        return root;
    }
};
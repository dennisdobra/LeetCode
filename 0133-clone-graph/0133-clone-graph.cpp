/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        // key -> value: old pointer -> new pointer
        unordered_map<Node*, Node*> pointerClone;

        queue<Node*> queue;

        // create clone for start node
        pointerClone[node] = new Node(node->val);
        queue.push(node);

        while (!queue.empty()) {
            Node* curr = queue.front();
            queue.pop();

            // traverse the original graph
            for (Node* neigh : curr->neighbors) {
                // if the neighbour is not cloned => we clone it
                if (!pointerClone.count(neigh)) {
                    pointerClone[neigh] = new Node(neigh->val);
                    queue.push(neigh);
                }

                pointerClone[curr]->neighbors.push_back(pointerClone[neigh]);
            }
        }

        return pointerClone[node];
    }
};
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

        // key -> value map
        // key = pointer to original node
        // value = pointer to cloned node
        unordered_map<Node*, Node*> map;

        // create clone for start node
        map[node] = new Node(node->val);

        // queue for the nodes in the original graph
        queue<Node*> queue;
        queue.push(node);

        while (!queue.empty()) {
            // take the first node from the queue (original node)
            Node* curr = queue.front();
            queue.pop();

            // iterate over the neighbours of the original node
            for (Node* neigh : curr->neighbors) {
                // if the neighbor has not been cloned => i clone it
                if (!map.count(neigh)) {
                    // clone the neighbor
                    map[neigh] = new Node(neigh->val);

                    // push the original neighbor in the queue
                    queue.push(neigh);
                }

                // push the pointers for the cloned neighbors in neighbor list for the cloned node

                // map[curr] = pointer to the cloned node of curr
                // map[curr]->neighbors = list of neighbors for the cloned node
                // map[neigh] = pointer to the cloned neigh
                map[curr]->neighbors.push_back(map[neigh]);
            }
        }

        return map[node];
    }
};
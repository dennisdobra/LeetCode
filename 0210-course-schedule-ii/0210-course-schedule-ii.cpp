class Solution {
public:

    /* TOPOLOGICAL SORT USING DFS */
    int WHITE = 0;
    int GREY = 1;
    int BLACK = 2;
    
    unordered_map<int, int> color;
    unordered_map<int, vector<int>> graph;
    stack<int> stack;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // By default, all vertices are WHITE (not visited)
        for (int i = 0; i < numCourses; i++) {
            color[i] = WHITE;
        }

        // create the graph (as an adjacency list)
        for (vector<int>& edge : prerequisites) {
            int first = edge[1];
            int second = edge[0];

            graph[first].push_back(second);
        }

        // If the node is unprocessed, call dfs on it
        for (int i = 0; i < numCourses; i++) {
            if (color[i] == WHITE && dfs(i) == true) {
                return {};
            }
        }

        vector<int> topoOrder;
        while (!stack.empty()) {
            int curr = stack.top();
            stack.pop();

            topoOrder.push_back(curr);
        }

        return topoOrder;
    }

    // function that detects if there is a cycle
    bool dfs(int node) {
        color[node] = 1;

        for (int neigh : graph[node]) {
            if (color[neigh] == 1) {
                // found a cycle
                return true;
            } else if (color[neigh] == 0) {
                if (dfs(neigh) == true) {
                    return true;
                }
            }
        }

        // no cycle detected starting dfs from 'node'
        color[node] = BLACK;
        stack.push(node);
        
        return false;
    }

    /* TOPOLOGICAL SORT USING BFS (KAHN'S ALGORITHM) */
};
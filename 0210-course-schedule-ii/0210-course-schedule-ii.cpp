class Solution {
public:

    /* TOPOLOGICAL SORT USING DFS */
    // int WHITE = 0;
    // int GREY = 1;
    // int BLACK = 2;
    
    // vector<int> color;
    // unordered_map<int, vector<int>> graph;
    // vector<int> topoOrder;

    // vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

    //     // By default, all vertices are WHITE (not visited)
    //     color = vector(numCourses, WHITE);

    //     // create the graph (as an adjacency list)
    //     for (vector<int>& edge : prerequisites) {
    //         int first = edge[1];
    //         int second = edge[0];

    //         graph[first].push_back(second);
    //     }

    //     // If the node is unprocessed, call dfs on it
    //     for (int i = 0; i < numCourses; i++) {
    //         if (color[i] == WHITE && dfs(i) == true) {
    //             return {};
    //         }
    //     }

    //     reverse(topoOrder.begin(), topoOrder.end());
    //     return topoOrder;
    // }

    // // function that detects if there is a cycle
    // bool dfs(int node) {
    //     color[node] = 1;

    //     for (int neigh : graph[node]) {
    //         if (color[neigh] == 1) {
    //             // found a cycle
    //             return true;
    //         } else if (color[neigh] == 0) {
    //             if (dfs(neigh) == true) {
    //                 return true;
    //             }
    //         }
    //     }

    //     // no cycle detected starting dfs from 'node'
    //     color[node] = BLACK;
    //     topoOrder.push_back(node);
        
    //     return false;
    // }

    /* TOPOLOGICAL SORT USING BFS (KAHN'S ALGORITHM) */
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> graph;

        vector<int> topoOrder;

        for (vector<int>& edge : prerequisites) {
            int src = edge[1];
            int dst = edge[0];

            graph[src].push_back(dst);
            indegree[dst]++;
        }

        // put in the queue all the nodes with indegree = 0
        queue<int> queue;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                queue.push(i);
            }
        }

        while (!queue.empty()) {
            int currNode = queue.front();
            queue.pop();

            for (int neigh : graph[currNode]) {
                // reduce the indegree of the neighbours by one
                indegree[neigh]--;

                // if the indegree of any neighbor becomes 0, add it to the queue
                if (indegree[neigh] == 0) {
                    queue.push(neigh);
                }
            }

            // add the currNode to the topo order
            topoOrder.push_back(currNode);
        }

        return topoOrder;
    }
};
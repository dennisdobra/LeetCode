class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> state; // 0 - not visited, 1 - visiting, 2 - fully porcessed

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build the graph
        for (vector<int>& edge : prerequisites) {
            int first = edge[1];
            int second = edge[0];

            graph[first].push_back(second);
        }

        // now i have to see if there is a cycle in the graph
        // i will do this by using DFS with 3 possible states for each node

        // first, mark all nodes as not visited
        state = vector(numCourses, 0);  

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0 && dfs(i) == true) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int node) {
        // mark the current node as 'visiting'
        state[node] = 1;

        for (int neigh : graph[node]) {
            if (state[neigh] == 0) {
                // go deeper
                if (dfs(neigh) == true) {
                    return true;
                }
            } else if (state[neigh] == 1) {
                // neighbor is already being visited
                // => found a cycle
                return true;
            }
        }

        // done with the current node
        // no cycle found with DFS for this node
        state[node] = 2;    
        return false;
    }
};
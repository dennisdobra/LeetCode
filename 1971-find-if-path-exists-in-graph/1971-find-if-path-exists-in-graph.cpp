class Solution {
public:
    vector<bool> seen;
    unordered_map<int, vector<int>> graph;

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;

        // build the graph
        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        seen = vector(n, false);
        seen[source] = true;
        return dfs(source, destination);
    }

    bool dfs(int node, int target) {
        for (int neigh : graph[node]) {
            if (seen[neigh] == false) {
                if (neigh == target) return true;

                seen[neigh] = true;
                return dfs(neigh, target);
            }
        }

        return false;
    }
};
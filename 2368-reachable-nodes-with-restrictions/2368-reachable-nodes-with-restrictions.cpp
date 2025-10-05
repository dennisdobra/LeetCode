class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;
    vector<int> visited;

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // build the graph
        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> restricted_nodes;
        for (int node : restricted) {
            restricted_nodes.insert(node);
        }

        seen = vector<bool>(n, false);
        seen[0] = true;

        int ans = dfs(0, restricted_nodes);
        return ans;
    }

    int dfs(int node, unordered_set<int>& restricted_nodes) {
        if (restricted_nodes.contains(node)) return 0;

        int ans = 1; // count the current node
        for (int neigh : graph[node]) {
            if (seen[neigh] == false) {
                seen[neigh] = true;
                ans += dfs(neigh, restricted_nodes);
            }
        }

        return ans;
    }
};
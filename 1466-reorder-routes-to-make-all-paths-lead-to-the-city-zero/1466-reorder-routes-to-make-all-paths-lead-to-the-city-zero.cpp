class Solution {
public:
    // original roads
    set<vector<int>> roads;

    // new undirected graph (to reach all nodes)
    unordered_map<int, vector<int>> graph;

    // vector to mark nodes as visited
    vector<bool> seen;

    int minReorder(int n, vector<vector<int>>& connections) {
        // put the original roads in a set for O(1) search
        for (vector<int>& road : connections) {
            roads.insert(road);
        }

        // make the original graph undirected
        for (vector<int>& edge : connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        seen = vector(n, false);

        // start DFS from 0
        seen[0] = true;
        return dfs(0);
    }

    int dfs(int node) {
        int ans = 0;
        for (int neigh : graph[node]) {
            if (seen[neigh] == false) {
                if (roads.contains({node, neigh})) {
                    // we have to flip this edge
                    ans++;
                }

                seen[neigh] = true;
                ans += dfs(neigh);
            }
        }

        return ans;
    }
};
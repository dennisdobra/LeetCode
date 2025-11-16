class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> seen;

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int provinces = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!seen.contains(i)) {
                dfs(i);
                provinces++;
            }
        }

        return provinces;
    }

    void dfs(int node) {
        for (int neigh : graph[node]) {
            if (!seen.contains(neigh)) {
                seen.insert(neigh);
                dfs(neigh);
            }
        }
    }
};
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> seen;

    int findCircleNum(vector<vector<int>>& isConnected) {
        // preprocessing
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = i + 1; j < isConnected.size(); j++) {
                if (isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int connected_components = 0;

        for (int i = 0; i < isConnected.size(); i++) {
            if (seen.contains(i)) {
                continue;
            }

            connected_components++;
            seen.insert(i);
            dfs(i);
        }

        return connected_components;
    }

    // RECURSIVE DFS
    void dfs(int node) {
        for (int neigh : graph[node]) {
            if (!seen.contains(neigh)) {
                seen.insert(neigh);
                dfs(neigh);
            }
        }
    }

    // ITERATIVE dfs
    void iterative_dfs(int node) {
        stack<int> stack;
        stack.push(node);

        while (!stack.empty()) {
            int curr = stack.top();
            stack.pop();

            for (int neigh : graph[curr]) {
                if (!seen.contains(curr)) {
                    seen.insert(curr);
                    stack.push(neigh);
                } 
            }
        }
    }
};
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> seen;
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // build the graph
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // start a DFS from 'source' node and see if it can reach 'target'
        seen.insert(source);
        return dfs(source, destination);
    }
    
    bool dfs(int src, int dst) {
        if (src == dst) return true;
        
        for (int neigh : graph[src]) {
            if (!seen.contains(neigh)) {
                seen.insert(neigh);
                if (dfs(neigh, dst) == true) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
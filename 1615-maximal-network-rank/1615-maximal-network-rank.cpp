class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto& road : roads) {
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }

        int maxRank = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = graph[i].size() + graph[j].size();
                // if there is an edge between city i and city j we only count it once
                if (graph[i].contains(j)) {
                    rank--;
                }
                maxRank = max(maxRank, rank);
            }
        }

        return maxRank;
    }
};
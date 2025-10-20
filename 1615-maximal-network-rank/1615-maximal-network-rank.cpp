class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<int>> graph;
        for (auto& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        int maxRank = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = graph[i].size() + graph[j].size();
                // dacă există muchie directă între i și j, scade 1
                if (find(graph[i].begin(), graph[i].end(), j) != graph[i].end()) {
                    rank--;
                }
                maxRank = max(maxRank, rank);
            }
        }

        return maxRank;
    }
};
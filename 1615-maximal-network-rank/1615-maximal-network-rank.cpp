class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // build the graph
        unordered_map<int, vector<int>> graph;
        for (vector<int>& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        int maxRank = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                // get current rank for citites i and j
                int currRank = graph[i].size() + graph[j].size();

                // check if there is a road from city i to city j
                for (int k = 0; k < graph[j].size(); k++) {
                    if (graph[j][k] == i) {
                        currRank--;
                        break;
                    }
                }

                maxRank = max(maxRank, currRank);
            }
        }

        return maxRank;
    }
};
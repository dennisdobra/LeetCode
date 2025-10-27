class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // city index -> list of directly connected cities
        unordered_map<int, unordered_set<int>> directlyConnected;

        for (vector<int> road : roads) {
            int src = road[0], dst = road[1];

            directlyConnected[src].insert(dst);
            directlyConnected[dst].insert(src);
        }

        int maxRank = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int currRank = directlyConnected[i].size() + directlyConnected[j].size();

                // if cities i and j are directly connected, only cound the road once
                if (directlyConnected[i].contains(j)) currRank = currRank - 1;

                if (currRank > maxRank) maxRank = currRank;
            }
        }

        return maxRank;
    }
};
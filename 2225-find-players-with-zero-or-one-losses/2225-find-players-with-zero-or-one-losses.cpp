class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);

        // player - matches lost
        unordered_map<int, int> loses;

        for (const auto& pair : matches) {
            loses[pair[1]]++;   // increase nr of loses for loser in current pair

            if (loses.find(pair[0]) == loses.end()) {
                loses[pair[0]] = 0;
            }
        }

        vector<int> winners;
        vector<int> one_loss;
        for (const auto& pair : loses) {
            if (pair.second == 0) {
                winners.push_back(pair.first);
            }

            if (pair.second == 1) {
                one_loss.push_back(pair.first);
            }
        }

        sort(winners.begin(), winners.end());
        sort(one_loss.begin(), one_loss.end());


        ans[0] = winners;
        ans[1] = one_loss;

        return ans;
    }
};
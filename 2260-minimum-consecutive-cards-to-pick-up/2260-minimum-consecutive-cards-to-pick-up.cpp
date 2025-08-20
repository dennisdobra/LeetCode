class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        /* sliding window */

        /* hash map */
        unordered_map<int,int> myMap;

        int ans = INT_MAX;
        for (int i = 0; i < cards.size(); i++) {
            if (myMap.find(cards[i]) != myMap.end()) {
                ans = min(ans, i - myMap[cards[i]] + 1);
            }

            myMap[cards[i]] = i;
        }

        if (ans == INT_MAX) return -1;

        return ans;
    }
};
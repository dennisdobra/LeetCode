class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> count;

        for (int num : nums) {
            count[num]++;
        }

        int ans = 0;
        for (auto& pair : count) {
            ans += pair.second * (pair.second - 1) / 2;
        }

        return ans;
    }
};
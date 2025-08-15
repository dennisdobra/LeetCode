class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> freq;

        for (vector<int>& arr : nums) {
            for (int x : arr) {
                freq[x]++;
            }
        }

        vector<int> ans;
        for (const auto& pair : freq) {
            if (pair.second == nums.size()) {
                ans.push_back(pair.first);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
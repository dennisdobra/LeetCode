class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> map;

        for (vector<int>& vec : nums) {
            for (int num : vec) {
                map[num]++;
            }
        }

        // get all elements that have frequency = nums.size();
        vector<int> ans;
        for (auto& pair : map) {
            if (pair.second == nums.size()) {
                ans.push_back(pair.first);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
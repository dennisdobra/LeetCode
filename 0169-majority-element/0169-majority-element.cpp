class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end()) {
                map[nums[i]]++;
            } else {
                map.insert({nums[i], 1});
            }
        }

        int max = 0, val;
        for (const auto& pair : map) {
            if (pair.second > max) {
                max = pair.second;
                val = pair.first;
            }
        }

        return val;
    }
};
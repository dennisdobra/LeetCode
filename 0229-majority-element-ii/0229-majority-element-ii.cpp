class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int minAppearances = nums.size() / 3;

        map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = 1;
            } else {
                map[nums[i]]++;
            }
        }

        vector<int> result;
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second > minAppearances) {
                result.push_back(it->first);
            }
        }

        return result;
    }
};
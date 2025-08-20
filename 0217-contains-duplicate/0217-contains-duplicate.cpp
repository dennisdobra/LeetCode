class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;

        for (int i = 0; i < nums.size(); i++) {
            if (freq.contains(nums[i])) {
                return true;
            }

            freq[nums[i]]++;
        }

        return false;
    }
};
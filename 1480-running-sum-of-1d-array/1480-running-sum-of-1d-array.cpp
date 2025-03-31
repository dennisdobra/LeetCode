class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> prefixSums = {nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            prefixSums.push_back(nums[i] + prefixSums.back());
        }
        
        return prefixSums;
    }
};
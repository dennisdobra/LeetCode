class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avg(nums.size(), -1);
        
        if (nums.size() < 2 * k) {
            return avg;
        }
        
        vector<long> prefix = {nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            prefix.push_back(prefix.back() + nums[i]);
        }
        
        for (int i = k; i < nums.size() - k; i++) {
            avg[i] = (prefix[i + k] - prefix[i - k] + nums[i - k]) / (2 * k + 1);
        }
        
        return avg;
    }
};
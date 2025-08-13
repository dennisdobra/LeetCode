class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long> prefix = {nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            prefix.push_back(prefix.back() + nums[i]);
        }

        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            long left_section = prefix[i];
            long right_section = prefix.back() - prefix[i];

            if (left_section >= right_section) {
                ans++;
            }
        }

        return ans;
    }
};
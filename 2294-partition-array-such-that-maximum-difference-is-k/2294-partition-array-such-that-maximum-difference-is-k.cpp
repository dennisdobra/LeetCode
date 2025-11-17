class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int currMin = nums[0];
        int numGroups = 1;

        for (int num : nums) {
            if (num - k > currMin) {
                currMin = num;
                numGroups++;
            }
        }

        return numGroups;
    }
};
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;

        sort(nums.begin(), nums.end());

        int sum = -1, delta = INT_MAX;
        while (left < right) {
            if (nums[left] + nums[right] >= k) {
                right--;
            } else {
                if (k - (nums[left] + nums[right]) < delta) {
                    delta = k - (nums[left] + nums[right]);
                    sum = nums[left] + nums[right];
                }

                left++;
            }
        }

        return sum;
    }
};
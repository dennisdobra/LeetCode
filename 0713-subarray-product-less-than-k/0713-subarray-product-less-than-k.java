class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int left = 0;
        int prod = 1;
        int ans = 0;

        if (k <= 1) return ans;

        for (int right = 0; right < nums.length; right++) {
            prod *= nums[right];

            while (prod >= k) {
                prod /= nums[left];
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
}
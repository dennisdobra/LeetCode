class Solution {
    public int waysToSplitArray_(int[] nums) {
        long prefix[] = new long[nums.length];

        prefix[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }

        int ans = 0;

        for (int i = 0; i < nums.length - 1; i++) {
            if (prefix[i] >= prefix[prefix.length - 1] - prefix[i]) {
                ans++;
            }
        }

        return ans;
    }

    public int waysToSplitArray(int[] nums) {
        long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int ans = 0;

        long left = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            left += nums[i];

            if (left >= totalSum - left) {
                ans++;
            }
        }

        return ans;
    }
}

class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int curr = 0;
        int left = 0;
        int ans = Integer.MAX_VALUE;

        for (int right = 0; right < nums.length; right++) {
            curr += nums[right];

            if (curr < target) continue;

            // here we have a valid window
            ans = Math.min(ans, right - left + 1);

            while (curr >= target) {
                curr -= nums[left];
                left++;

                if (curr >= target) {
                    ans = Math.min(ans, right - left + 1);
                }
            }
        }



        return ans != Integer.MAX_VALUE ? ans : 0;
    }
}
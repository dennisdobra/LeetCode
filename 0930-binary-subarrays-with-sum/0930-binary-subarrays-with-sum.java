class Solution {
    public int numSubarraysWithSum_(int[] nums, int goal) {
        // map to track the frequency of each prefix sum
        Map<Integer, Integer> prefix = new HashMap<>();

        // add the empty prefix
        prefix.put(0, 1);

        int ans = 0;
        int curr = 0;
        for (int i = 0; i < nums.length; i++) {
            // add the current element to the total prefix
            curr += nums[i];

            // if we've previously seen a prefix equal to 'curr - goal'
            // it means there is a subarray with a sum equal to goal
            // ex: if we've previously seen a total prefix equal to 2
            //     and now the total prefix is equal to 6 and the goal
            //     is 4 => there is a valid subarray starting from where
            //     we've seen the total prefix 2 up until the current
            //     element equal to 4
            ans += prefix.getOrDefault(curr - goal, 0);

            // add the current total prefix to the map
            prefix.put(curr, prefix.getOrDefault(curr, 0) + 1);
        }

        return ans;
    }

    // OBS: Compared to problem 560 (Subarray sum equals k), where we could have
    //      negative integers and tehrefore sliding window was not an option,
    //      in this problem we can use sliding window, as the window can only increase
    public int numSubarraysWithSum(int[] nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

    // finds all subarrays with a sum equal to or less than limit
    public int atMost(int[] nums, int limit) {
        // alternative for (left <= right)
        // if (limit < 0) return 0; 

        int left = 0;
        int curr = 0;
        int ans = 0;
        for (int right = 0; right < nums.length; right++) {
            // add the current element to the window
            curr += nums[right];

            // make sure the window is still valid
            while (left <= right && curr > limit) {
                curr -= nums[left];
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
}
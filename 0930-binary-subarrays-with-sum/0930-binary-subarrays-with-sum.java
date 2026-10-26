class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
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
}
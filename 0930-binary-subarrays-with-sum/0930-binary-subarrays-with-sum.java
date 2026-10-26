class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        // map to track the frequency of each prefix sum
        Map<Integer, Integer> prefix = new HashMap<>();

        // add the empty prefix
        prefix.put(0, 1);

        int curr = 0;
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            curr += nums[i];

            ans += prefix.getOrDefault(curr - goal, 0);

            prefix.put(curr, prefix.getOrDefault(curr, 0) + 1);
        }

        return ans;
    }
}
class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();

        int ans = 0;
        int left = 0;
        for (int right = 0; right < nums.length; right++) {
            // increment the frequency of the current element
            map.put(nums[right], map.getOrDefault(nums[right], 0) + 1);

            // keep the window valid
            while (map.get(nums[right]) > k) {
                map.put(nums[left], map.get(nums[left]) - 1);
                left++;
            }

            // here we have a valid window
            ans = Math.max(ans, right - left + 1);
        }

        return ans;
    }
}
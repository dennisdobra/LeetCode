class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        // map to track the unique elements in the window
        Map<Integer, Integer> map = new HashMap<>();

        int left = 0;
        int ans = 0;
        int curr = 0;
        for (int right = 0; right < nums.length; right++) {
            // add the current element to the window
            curr += nums[right];
            map.put(nums[right], map.getOrDefault(nums[right], 0) + 1);

            // make sure the window is valid
            while (map.get(nums[right]) > 1) {
                curr -= nums[left];
                map.put(nums[left], map.get(nums[left]) - 1);
                left++;

                if (map.get(nums[left]) == 0) {
                    map.remove(nums[left]);
                }
            }

            ans = Math.max(ans, curr);
        }

        return ans;
    }
}
class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
    
        // empty prefix has a sum of 0 (if we have a subarray starting at index 0 with a sum of k
        // we will miss it when we will look for curr - k, if we don t add the empty prefix)
        map.put(0, 1);

        int curr = 0;
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            // addthe current number to the total prefix sum
            curr += nums[i];

            // if (map.containsKey(curr - k)) {
            //     ans += map.get(curr - k);
            // }

            ans += map.getOrDefault(curr - k, 0);

            map.put(curr, map.getOrDefault(curr, 0) + 1);
        }

        return ans;
    }
}
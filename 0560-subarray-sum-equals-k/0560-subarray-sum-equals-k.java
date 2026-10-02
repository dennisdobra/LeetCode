class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer,Integer> map = new HashMap<>();
    
        // empty prefix has a sum of 0
        map.put(0, 1);

        int curr = 0;
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            // addthe current number to the total prefix sum
            curr += nums[i];

            if (map.containsKey(curr - k)) {
                ans += map.get(curr - k);
            }

            map.put(curr, map.getOrDefault(curr, 0) + 1);
        }

        return ans;
    }
}
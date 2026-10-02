class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);

        int curr = 0;
        int ans = 0;
        for (int num : nums) {
            curr += num % 2;

            ans += map.getOrDefault(curr - k, 0);

            map.put(curr, map.getOrDefault(curr, 0) + 1);
        }

        return ans;
    }
}
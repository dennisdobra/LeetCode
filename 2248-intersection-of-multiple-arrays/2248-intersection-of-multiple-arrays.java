class Solution {
    public List<Integer> intersection(int[][] nums) {
        Map<Integer,Integer> map = new HashMap<>();

        // O(N * M) Time Complexity, where N is the length of nums and M is avg length of nums[i]
        for (int[] arr : nums) {
            for (int num : arr) {
                map.put(num, map.getOrDefault(num, 0) + 1);
            }
        }

        List<Integer> ans = new ArrayList<>();

        // O(N * M) Time Complexity worst case, where every element is unique
        for (var entry : map.entrySet()) {
            if (entry.getValue() == nums.length) {
                ans.add(entry.getKey());
            }
        }

        // O(M * logM) Time Complexity worst case, where every nums[i] array has the same M elements
        Collections.sort(ans);

        // Overall Time Complexity: O(N * M + M * logM)
        // Space Complexity: O(N * M) for the map if every element is unique

        return ans;
    }
}
class Solution {
    public int numIdenticalPairs_(int[] nums) {
        // every num with the indices in the array
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (!map.containsKey(nums[i])) {
                map.put(nums[i], new ArrayList<>());
            }

            map.get(nums[i]).add(i);
        }

        int pairs = 0;
        for (var list : map.values()) {
            pairs += (list.size() * (list.size() - 1)) / 2;
        }

        return pairs;
    }

    public int numIdenticalPairs(int[] nums) {
        // frequency of each number in nums
        int[] count = new int[101];

        int pairs = 0;
        for (int num : nums) {
            pairs += count[num];
            count[num]++;
        }

        return pairs;
    }
}